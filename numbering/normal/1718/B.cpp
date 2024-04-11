#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int A[100005];
int F[58];
int N;
typedef pair<int,int> P;
set<P> S;
bool isPos = false;
bool backtrack(int i, int v) {
    if(isPos) return true;
    if(i==-1) {
        isPos = true;
        return true;
    }
    P t = *S.rbegin();
    S.erase(t);
    P t2 = P(-1,-1);
    if(S.size()>0) t2 = *S.rbegin();
    if(t.first < F[i] || t.second == v) {
        S.insert(t);
    }
    else {
        S.insert(P(t.first-F[i],t.second));
        if(backtrack(i-1, t.second)) return true;
        S.erase(P(t.first-F[i],t.second));
        S.insert(t);
    }
    S.erase(t2);
    if(t2.first < F[i] || t2.second == v) {
        S.insert(t2);
    }
    else {
        S.insert(P(t2.first - F[i], t2.second));
        if(backtrack(i-1, t2.second)) return true;
        S.erase(P(t2.first-F[i], t2.second));
        S.insert(t2);
    }
    return false;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    F[0] = F[1] = 1;
    int sum = 2;
    for(int i = 2; i < 55; i++) {
        F[i] = F[i-1] + F[i-2];
        /*if(F[i] > 1e11) {
            cout << i;
            return 0;
            //54 is limit
        }*/
        //sum += F[i];
        //cout << i << " : " << sum <<' ' << F[i]<< '\n';
        //if(i%2==0) sum2 += F[i];
        //else sum1 += F[i];
        //cout << i << " : " << F[i] << ' ' << (i%2==0?sum2:sum1) << '\n';
    }
    while(t--) {
        cin >> N;
        int i, j;
        isPos = false;
        for(i=0;i<N;i++) cin >> A[i];
        int sum = 0;
        for(i=0;i<N;i++) sum += A[i];
        int sum2 = 0, pt = -1;
        for(i=0;i<55;i++) {
            sum2 += F[i];
            if(sum2 == sum) {
                pt = i;
                break;
            }
        }
        if(pt==-1) {
            cout << "NO\n";
            continue;
        }
        S = set<P> {};
        for(i=0;i<N;i++) S.insert(P(A[i],i));
        if(backtrack(pt, -1)) cout << "YES\n";
        else cout << "NO\n";
    }
}