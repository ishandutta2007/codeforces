#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
int n,m,q,T,k;




int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    scanf("%d %d %d" , &n, &m, &k);
    int curr = 0;
    bool hole[1000001] = {0};
    for(ll c1 = 0; c1 < m; c1++){
        int a;
        scanf("%d" , &a);
        a--;
        hole[a] = 1;
    }
    for(ll c1 = 0; c1 <  k; c1++){
        int a,b;
        scanf("%d" , &a);
        scanf("%d" , &b);
        a--;b--;
        if(!hole[curr]){
            if(curr == a){
                curr = b;
            }
            else{
                if(curr == b)curr = a;
            }
        }
    }

    cout << curr+1 << "\n";
    return 0;
}