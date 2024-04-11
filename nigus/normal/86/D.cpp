#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <stdio.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;

int n,m,q,p,d,h;
//ll T;


vector<int> A;
vector<int> B;

vector<ll> L;
vector<ll> R;
vector<ll> ind;
vector<ll> block;
vector<ll> ANS;

vector<int> freq;

ll ans = 0;

bool comp(ll i ,ll j){
if(block[i] == block[j]){return R[i] < R[j];}
return block[i] < block[j];
}

void add(ll i){
if(i == -1){return;}
//ans += (2*freq[A[i]] + 1) * A[i];
ans += freq[A[i]]*B[i];
ans += A[i];
freq[A[i]]++;
return;
}

void rem(ll i){
if(i == -1){return;}
//ans -= (2*freq[A[i]] - 1) * A[i];
ans -= freq[A[i]]*B[i];
ans += A[i];
freq[A[i]]--;
return;
}

int main()
{
   ll c1,c2,c3,c4,c5,c6;
    int a ,b,c,d,e,g;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    //cin >> n >> q;
    scanf("%d %d" , &n , &q);
    for(c1 = 0; c1 < 1000001; c1++){
        freq.push_back(0);
    }

    for(c1 = 0; c1 < n; c1++){
        //cin >> a;
        scanf("%d" , &a);
        A.push_back(a);
        B.push_back(2*a);
    }

    for(c1 = 0; c1 < q; c1++){
        //cin >> a >> b;
        scanf("%d %d" , &a , &b);
        a--;
        b--;
        ind.push_back(c1);
        block.push_back(a/sqrt(n));
        L.push_back(a);
        R.push_back(b);
        ANS.push_back(0);
    }
    sort(ind.begin() , ind.end() , comp);

    ll l , r;

    l = -1;
    r = -1;

    for(c1 = 0; c1 < q; c1++){

        a = ind[c1];

        if(r < R[a]){
            while(r < R[a]){
                r++;add(r);
            }
        }
        else{
            while(r > R[a]){
                rem(r);r--;
            }
        }

        if(l < L[a]){
            while(l < L[a]){
                rem(l);l++;
            }
        }
        else{
            while(l > L[a]){
                l--;add(l);
            }
        }

        ANS[a] = ans;


    }

    for(c1 = 0; c1 < q; c1++){
        cout << ANS[c1] << "\n";
        //printf("%d\n" , ANS[c1]);
    }

	return 0;
}