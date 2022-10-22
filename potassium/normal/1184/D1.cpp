#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define fr front()
#define po pop()
#define ba back()
#define F first
#define S second
#define printv(a, b) bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n"

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000001;

int main(){

    StarBurstStream
    
    int n, k, m, t;
    cin >> n >> k >> m >> t;

    for(int i = 0; i < t; i++){

        int a, b;
        cin >> a >> b;

        if(a == 1){
            if(b <= k){
                k++;
            }
            n++;
        }
        else{
            if(b < k){
                k -= b;
                n -= b;
            }
            else{
                n = b;
            }
        }

        cout << n << " " << k << "\n";

    }

    return 0;
}