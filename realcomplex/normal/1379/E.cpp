#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const int M = 20;

vector<int> soln[M][M];

int compute(vector<int> sha){
    vector<int> sz(sha.size(), 1);
    vector<int> out[sha.size()];
    for(int i = sha.size() - 1; i > 0 ; i -- ){
        sz[sha[i]] += sz[i];
        out[sha[i]].push_back(i);
    }
    int l1, l2;
    int bb = 0;
    for(int i = 0 ; i < sha.size(); i ++ ){
        if(out[i].size() == 2){
            l1 = sz[out[i][0]];
            l2 = sz[out[i][1]];
            if(l1 > l2) swap(l1, l2);
            if(l1 * 2 <= l2){
                bb ++ ;
            }
        }
    }
    return bb;

}

void brute(int cid, vector<int> pp){
    if(cid == pp.size()){
        int bal = compute(pp);
        soln[pp.size()][bal] = pp;
        return;
    }
    brute(cid + 1, pp);
    if(pp.size() + 2 < M){
        pp.push_back(cid);
        pp.push_back(cid);
        brute(cid+1, pp);
    }
}

bool ish(int n){
    if((n&(n+1))==0){
        return true;
    }
    return false;
}

int res[N];

bool valid(int n, int s1, int s2){
    if(s1 > s2) swap(s1, s2);
    if(ish(s1) && ish(s2)) return false;
    int cn = !ish(s1) + !ish(s2) + (s1 * 2 <= s2);
    if(cn > 1) return false;
    return true;
}

int cnt=1;

void bins(int n, int c){
    int root = cnt;
    res[cnt]=c;
    cnt ++ ;
    if(n==1){
        return;
    }
    bins(n/2,root);
    bins(n/2,root);
}

void solve1(int n, int c){
    int root = cnt;
    cnt ++ ;
    res[root] = c;
    int k = 1;
    while((k * 2 - 1) < n){
        k *= 2;
    }
    int sz1 = (k-1);
    int sz2 = (n-1-sz1);
    if(!valid(n,sz1,sz2)){
        k /= 2;
        sz1 = k-1;
        sz2 = (n-1-sz1);
    }
    if(ish(sz1)) bins(sz1,root);
    else solve1(sz1,root);
    if(ish(sz2)) bins(sz2,root);
    else solve1(sz2,root);
}

void extend(vector<int> pp, int c){
    res[cnt] = c;
    for(int i = 1; i < pp.size(); i ++ ){
        res[cnt+i]=pp[i]+cnt;
    }
    cnt += pp.size();
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    if(n % 2 == 0){
        cout << "NO\n";
        return 0;
    }
    if(k > max((n-3)/2,0)){
        cout << "NO\n";
        return 0;
    }
    brute(0,{-1});
    int par = 0;
    while(n > M && k > 1){
        if(k == 2){
            if(!ish(n-2)){
                n -= 2;
                res[cnt+1]=cnt;
                res[cnt+2]=cnt;
                par = cnt;
                cnt += 2;
            }
            else{
                n -= 4;
                res[cnt+1] = cnt;
                res[cnt+2] = cnt + 1;
                res[cnt+3] = cnt + 1;
                res[cnt+4] = cnt;
                par = cnt;
                cnt += 4;
            }
        }
        else{
            n -= 2;
            res[cnt+1] = cnt;
            res[cnt+2] = cnt;
            par = cnt;
            cnt += 2;
        }
        k--;
    }
    if(k == 0){
        if(!ish(n)){
            cout << "NO\n";
            return 0;
        }
        bins(n,par);
    }
    else if(k == 1){
        if(ish(n)){
            cout << "NO\n";
            return 0;
        }
        solve1(n,par);
    }
    else{
        if(soln[n][k].empty()){
            cout << "NO\n";
            return 0;
        }
        extend(soln[n][k],par);
    }
    cout << "YES\n";
    for(int i = 1; i < cnt; i ++ ){
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}