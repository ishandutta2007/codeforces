#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 52;
int main(){
    fastIO;
    int n;
    cin >> n;
    vector<int> c(n);
    int l = 0, r = 0;
    int bad = 0;
    for(int i = 0 ; i < n; i ++ ){
        cin >> c[i];
        if(c[i] == 1)
            l = i, r = i;
    }
    vector<vector<int>> sol;
    int x;
    int id;
    int sz;
    for(int i = 2 ; i <= n; i ++ ){
        l=n-1;
        r=0;
        for(int j = 0; j < n; j ++ ){
            if(c[j]<i)
                l=min(l,j),r=max(r,j);
            if(c[j] == i)
                x = j;
        }

        vector<int> szs;
        if(x > r){
            if(l > 0){
                szs.push_back(l);
            }
            if(bad){
                szs.push_back(1);
                szs.push_back(r-l);
            }
            else{
                szs.push_back(r-l+1);
            }
            szs.push_back(x-r);
            if(n - x - 1 > 0)
                szs.push_back(n-x-1);
            bad = 1;
        }
        else{
            if(x > 0)
                szs.push_back(x);
            szs.push_back(l-x);
            if(bad){
                szs.push_back(1);
                szs.push_back(r-l);
            }
            else{
                szs.push_back(r-l+1);
            }
            if(r < n - 1)
                szs.push_back(n-1-r);
            bad = 0;
        }
        sol.push_back(szs);
        vector<vector<int>> cut;
        id = 0;
        for(auto x : szs){
            cut.push_back({});
            for(int j = 0; j < x; j ++ ){
                cut.back().push_back(c[id]);
                id ++ ;
            }
        }
        reverse(cut.begin(), cut.end());
        id = 0;
        for(auto e : cut){
            for(auto y : e){
                c[id]=y;
                id ++ ;
            }
        }
    }

    if(bad){
        sol.push_back({1, n - 1});
    }

    cout << sol.size() << "\n";
    for(auto x : sol){
        cout << x.size() << " ";
        for(auto y : x){
            cout << y << " ";
        }
        cout << "\n";
    }
    return 0;
}