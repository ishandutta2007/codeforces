#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,q,T,k;

vector<vector<ll> > R;


ll ANS1[7001] = {0};
ll ANS2[7001] = {0};

ll deg1[7001] = {0};
ll deg2[7001] = {0};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

   ll c1,c2,c3,c4,c5,c6;
   ll a,b,c;

   cin >> n;


    cin >> a;
    vector<ll> A;
    for(c1 = 0; c1 < a; c1++){
        cin >> b;
        A.push_back(b);
    }
    R.push_back(A);
    A.clear();
    cin >> a;
    for(c1 = 0; c1 < a; c1++){
        cin >> b;
        A.push_back(b);
    }
    R.push_back(A);

    for(c1 = 1; c1 < n; c1++){
        for(c2 = 0; c2 < R[0].size(); c2++){
            deg1[c1]++;
        }
        for(c2 = 0; c2 < R[1].size(); c2++){
            deg2[c1]++;
        }
    }


    queue<pair<ll,ll> > Q;
    Q.push({-1,0});
    bool mark[7001][2] = {0};
    mark[0][0] = 1;
    while(!Q.empty()){

        pair<ll,ll> P = Q.front();
        Q.pop();
        a = P.first;
        b = P.second;
        if(a == -1){
            ANS2[b] = -1;
            for(c1 = 0; c1 < R[0].size(); c1++){
                c = (n + b - R[0][c1])%n;
                if(!mark[c][1] && c != 0){
                    mark[c][1] = 1;
                    Q.push({1 , c});
                }
            }
        }
        else{
            ANS1[b] = 1;
            for(c1 = 0; c1 < R[1].size(); c1++){
                c = (n + b - R[1][c1])%n;
                deg2[c]--;
                if(!mark[c][0] && deg2[c] == 0 && c != 0){
                    mark[c][0] = 1;
                    Q.push({-1 , c});
                }
            }
        }
    }

    Q.push({-1,0});
    bool mark2[7001][2] = {0};
    mark2[0][0] = 1;

    while(!Q.empty()){

        pair<ll,ll> P = Q.front();
        Q.pop();
        a = P.first;
        b = P.second;
        if(a == -1){
            ANS1[b] = -1;
            for(c1 = 0; c1 < R[1].size(); c1++){
                c = (n + b - R[1][c1])%n;
                if(!mark2[c][1] && c != 0){
                    mark2[c][1] = 1;
                    Q.push({1 , c});
                }
            }
        }
        else{
            ANS2[b] = 1;
            for(c1 = 0; c1 < R[0].size(); c1++){
                c = (n + b - R[0][c1])%n;
                deg1[c]--;
                if(!mark2[c][0] && deg1[c] == 0 && c != 0){
                    mark2[c][0] = 1;
                    Q.push({-1 , c});
                }
            }
        }
    }

    for(c1 = 0; c1 < n-1; c1++){
        ll a = ANS1[c1+1];
        if(a == -1)cout << "Lose ";
        if(a == 0)cout << "Loop ";
        if(a == 1)cout << "Win ";
    }cout << "\n";
    for(c1 = 0; c1 < n-1; c1++){
        ll a = ANS2[c1+1];
        if(a == -1)cout << "Lose ";
        if(a == 0)cout << "Loop ";
        if(a == 1)cout << "Win ";
    }cout << "\n";

    return 0;
}