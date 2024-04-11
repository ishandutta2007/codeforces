#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,d;
const ll big = 1000000007;

vi flips(int mask){
    vi ANS;
    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 1; c2 < n; c2++){
            int a = c1-c2;
            int b = c1;
            int c = c1+c2;
            if(a >= 0 && c  < n){
                int xo = ((1 << a)^((1 << b)^(1 << c)) );
                ANS.push_back(mask^xo);
            }
        }
    }
    return ANS;
}

bool mark[1000001] = {0};
int par[1000001] = {0};

void bfs(){
    queue<ll> Q;
    Q.push(0);
    par[0] = -1;
    while(!Q.empty()){
        int a = Q.front();
        Q.pop();
        if(!mark[a]){
            mark[a] = 1;
            vi A = flips(a);
            for(int c1 = 0; c1 < sz(A); c1++){
                int b = A[c1];
                if(!mark[b]){
                    par[b] = a;
                    Q.push(b);
                }
            }
        }

    }

}

int tonum(string s){
    int ans = 0;
    for(int c1 = s.length()-1; c1 >= 0; c1--){
        ans *= 2;

        ans += s[c1]-'0';
    }
    return ans;
}

string tostr(int a){
    string ans = "";
    int a2 = a;
    for(int c1 = 0; c1 < n; c1++){
        if(a2%2 == 0){
            ans += '0';
        }
        else{
            ans += '1';
        }
        a2 /= 2;
    }
    reverse(all(ans));
    return ans;
}

vi getx(int mask1, int mask2){
    vi ANS;
    int xo = (mask1^mask2);
    for(int c1 = 0; c1 < n; c1++){
        if(xo%2 == 1){
            ANS.push_back(c1);
        }
        xo /= 2;
    }
   // reverse(all(ANS));
    return ANS;
}

vector<vi> RES;

vi A,A2;

bool check(){

    for(int c1 = 0; c1 < sz(RES); c1++){
        for(int c2 = 0; c2 < 3; c2++){
            A2[RES[c1][c2]] ^= 1;
        }
    }
    for(int c1 = 0; c1 < sz(A2); c1++){
        if(A2[c1] == 1)return 0;
    }
    return 1;
}

int main() {
  //  ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
   // n = 128300;

    int n2 = n;
    n = min(16ll,n);

    bfs();

    for(int c1 = 0; c1 < n2; c1++){
        cin >> a;
       // a = rand()%2;a = 1;
      //  if(rand()%1000 == 0)a = 0;

        A.push_back(a);
        A2.push_back(a);
    }

/*
    for(int c1 = n2-1; c1 >= 2; c1--){
        if(A[c1] == 1){
            A[c1] ^= 1;
            A[c1-1] ^= 1;
            A[c1-2] ^= 1;
            vi B;
            B.push_back(c1-2);
            B.push_back(c1-1);
            B.push_back(c1);
            RES.push_back(B);
        }
    }
*/
    int lim = 20;
    if(n2 > 0){
    for(int c1 = n2-1; c1 >= 5; c1--){
        bool done = 0;
        if(A[c1] == 1){
            for(int c2 = 1; c2 <= lim; c2++){
                a = c1;
                b = c1-c2;
                c = c1-2*c2;
                if(c >= 0){

                    if(A[a] == 1 && A[b] == 1 && A[c] == 1){
                        A[a] = 0;
                        A[b] = 0;
                        A[c] = 0;
                        vi B;
                        B.push_back(a);
                        B.push_back(b);
                        B.push_back(c);
                        RES.push_back(B);
                        done = 1;
                        break;
                    }

                }
            }

            if(!done){
                for(int c2 = 0; c2 < lim; c2++){
                    ll ra = RAND_MAX*rand()+rand();
                    ra %= (c1/2 - 1);
                    ra++;
                    a = c1;
                    b = c1-ra;
                    c = c1-2*ra;

                    if(c >= 0){
                        if(A[b] == 1){
                            A[a] = 0;
                            A[b] = 0;
                            A[c] ^= 1;
                            vi B;
                            B.push_back(a);
                            B.push_back(b);
                            B.push_back(c);
                            RES.push_back(B);
                            done = 1;
                            break;
                        }
                    }

                }
                if(!done){

                    ll h = c1/2-1;

                    A[c1] ^= 1;
                    A[c1-h] ^= 1;
                    A[c1-2*h] ^= 1;
                    vi B;
                    B.push_back(c1);
                    B.push_back(c1-h);
                    B.push_back(c1-2*h);
                    RES.push_back(B);
                    done = 1;

                }
            }
        }
    }
    }
    string s = "";

    for(int c1 = 0; c1 < n; c1++){
        if(A[c1] == 0){
            s += '0';
        }
        else{
            s += '1';
        }
    }

    a = tonum(s);
    if(!mark[a]){
        cout << "NO\n";
        return 0;
    }

    while(par[a] != -1){
        vi B = getx(a,par[a]);
        RES.push_back(B);
        a = par[a];
    }

    cout << "YES\n";
    cout << sz(RES) << "\n";
    for(int c1 = 0; c1 < sz(RES); c1++){
        cout << RES[c1][0]+1 << " " << RES[c1][1]+1 << " " << RES[c1][2]+1 << "\n";
    }

   // assert(check());
   // cerr << sz(RES) << " " << n2/3+12 << "\n";
    //assert(sz(RES) <= n2/3+12);

    return 0;
}