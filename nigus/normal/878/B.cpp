#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,k,q,w,h,T;

vector<ll> A;
vector<ll> B;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> k >> m;

    ll prev = -1;
    ll same = 1;

    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        if(a == prev){same++;}else{same = 1;}
        B.push_back(same);
        if(same == k){
            for(ll c2 = 0; c2 < k; c2++){
                A.pop_back();
                B.pop_back();
            }
        }
        prev = -1;
        same = 1;
        if(sz(A) != 0){
            prev = A[sz(A)-1];
            same = B[sz(B)-1];
        }
    }

   /* for(ll c1 = 0; c1 < sz(A); c1++){
        cout << A[c1] << " ";
    }
*/
    n = sz(A);

    ll r = n-1;
    ll l;
    ll c1 = 0;
    while(c1 < n){
        l = c1;
        //cout << l << "\n";
        if(r-l+1 < k){
            break;
        }
        else{
            ll r2 = r;
            bool fail = 0;
            ll amt = 1;
            for(ll c2 = 0; c2 < k-1; c2++){
                if(A[l] != A[r2]){
                    break;
                }
                amt++;
                r2--;
            }
            ll t = A[l];
            ll oldl = l;
            if(amt < k){
                l++;
                while(A[l] == t){
                    l++;
                    amt++;
                    if(amt == k)break;
                }
                l--;
            }
            if(amt < k){l = oldl;break;}
            if(fail)break;
            r = r2;

        }
        c1 = l;
        c1++;
    }


    //cout << l<< " " << r << "\n";


    if(l >= r+1){
        cout << "0\n";
    }
    else{


        bool sim = 1;
        ll one = A[l];
        for(ll c1 = l; c1 <= r; c1++){
            if(A[c1] != one)sim = 0;
        }

        if(sim){

            vector<ll> A2;
            vector<ll> A1;
            c = ((m-2)*(r-l+1))%k;
            ll k1 = 0;
            ll k2 = 0;
            for(ll c1 = r; c1 >= 0; c1--){
                if(A[c1] != one)break;
                k1++;
                c++;
            }

            for(ll c1 = l; c1 < n; c1++){
                if(A[c1] != one)break;
                k2++;
                c++;
            }

            c %= k;

            for(ll c1 = 0; c1 <= r-k1; c1++){
                A1.push_back(A[c1]);
            }

            for(ll c1 = l+k2; c1 < n; c1++){
                A2.push_back(A[c1]);
            }

            if(c != 0){
                cout << sz(A1)+sz(A2)+c << "\n";
            }
            else{

                A.clear();
                B.clear();
                vector<ll> AA;
                for(ll c1 = 0; c1 < sz(A1); c1++){
                    AA.push_back(A1[c1]);
                }
                for(ll c1 = 0; c1 < sz(A2); c1++){
                    AA.push_back(A2[c1]);
                }

                n = sz(AA);


                prev = -1;
                same = 1;

                for(ll c1 = 0; c1 < n; c1++){
                    a = AA[c1];
                    A.push_back(a);
                    if(a == prev){same++;}else{same = 1;}
                    B.push_back(same);
                    if(same == k){
                        for(ll c2 = 0; c2 < k; c2++){
                            A.pop_back();
                            B.pop_back();
                        }
                    }
                    prev = -1;
                    same = 1;
                    if(sz(A) != 0){
                        prev = A[sz(A)-1];
                        same = B[sz(B)-1];
                    }
                }

                cout << sz(A) << "\n";

            }

        }
        else{

            cout << m*n -  (m-1)*(l + (n-1-r)) << "\n";

        }

    }

    return 0;
}