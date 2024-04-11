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
ll n,m,k,q,h,T;

vector<ll> A;
ll SUMS[10000000] = {0};
ll SUMS2[10000000] = {0};
vector<ll> B;
vector<ll> ind;
vector<ll> ind2;
bool mark[140] = {0};
vector<ll> ANS;
bool win = 0;
ll cot = 0;

void brute(ll i){
    if(win)return;
    for(ll c4 = 0; c4 < n; c4++){
        ll c1 = (c4+i)%n;
        ll a = ind2[(ind[c1]+1)%n];
        //cout << i << " " << A[a] << " " << ind[i] << "\n";
        if(win)return;
        if(!mark[a] && A[i] != A[a]){
           // cout << i << " " << c1 << "\n";
            bool fail = 0;
            for(ll c2 = 0; c2 < (1 << i); c2++){

                cot++;
                if(cot > 40000000)return;

                if(c2 + (1 << i) == (1 << n)-1)break;
                if(SUMS2[c2] + A[a] == SUMS[c2 + (1 << i)]){ fail = 1;break;
                }
            }
            if(!fail){

                for(ll c2 = 0; c2 < (1 << i); c2++){
                    SUMS2[c2+(1 << i)] = SUMS2[c2] + A[a];
                }
                mark[a] = 1;
                B.push_back(A[a]);
                if(i == n-1){
                    ANS.clear();
                    win = 1;
                    for(ll c2 = 0; c2 < n; c2++){
                        ANS.push_back(B[c2]);
                    }
                    return;
                }
                else{
                    brute(i+1);
                }
                mark[a] = 0;
                B.pop_back();
            }
        }
    }
}

bool comp(ll i, ll j){
    return A[i] < A[j];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    cin >> n;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        ind.push_back(c1);
        ind2.push_back(c1);
    }
    for(ll c1 = 0; c1 < (1 << n); c1++){
        a = 0;
        for(ll c2 = 0; c2 < n; c2++){
            if((c1&(1 << c2)) != 0)a += A[c2];
        }
        SUMS[c1] = a;
    }
    //random_shuffle(all(ind));
    sort(all(ind2),comp);
    for(ll c1 = 0; c1 < n; c1++)ind[ind2[c1]] = c1;
    brute(0);
    if(win){

        for(ll c1 = 0; c1 < n; c1++){
            cout << ANS[c1] << " ";
        }
    }
    else{
        if(n == 1){

            cout << A[0] << "\n";
        }
        else{
        cout << "-1\n";}
    }
    return 0;
}