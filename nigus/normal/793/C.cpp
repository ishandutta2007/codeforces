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
ll n,m,q,T,k;

struct pt{
ld x,y;
};

struct pti{
ll x,y;
};

vector<pti> X;
vector<pti> V;

vector<ll> ind;
vector<pti> iotime;
vector<bool> io;

pti X1;
pti X2;
ld eps = 0.0000000001;
pti timex(ll i, ll x, ll y1, ll y2){
    pti ANS;
    ANS.x = -1;
    ANS.y = 1;
    if(V[i].x == 0){

        return ANS;

    }

    ld ans = ld(x - X[i].x)/ld(V[i].x);

    ld y = X[i].y + ans*V[i].y;



    //if(i == 3)cout << ans << " "<< y << "  " << min(y1,y2) << " " << max(y1,y2) << "\n";

    if(V[i].y == 0 && (abs(y-y1) <= eps || abs(y-y2) <= eps) )return ANS;

    if((ans >= 0.0 || x == X[i].x) && y >= ld(min(y1,y2)) && y <= ld(max(y1,y2))){
        //cout << i << " ans: " << ans << "  y: " << y << "   xxx\n";
        ANS.x = abs(x - X[i].x);
        ANS.y = abs(V[i].x);
    }
    return ANS;
}

pti timey(ll i, ll y, ll x1, ll x2){


    pti ANS;
    ANS.x = -1;
    ANS.y = 1;
    if(V[i].y == 0){

        return ANS;

    }

    ld ans = ld(y - X[i].y)/ld(V[i].y);

    ld x = X[i].x + ans*V[i].x;



    //if(i == 3)cout << ans << " "<< x << "  " << min(x1,x2) << " " << max(x1,x2) << "\n";

    if(V[i].x == 0 && (abs(x-x1) <= eps || abs(x-x2) <= eps) )return ANS;


    if((ans >= 0.0 || y == X[i].y) && x >= min(x1,x2) && x <= max(x1,x2)){
        //cout << i << " ans: " << ans << "  x: " << x << "   yyy\n";
        ANS.x = abs(y - X[i].y);
        ANS.y = abs(V[i].y);
    }
    return ANS;
}

bool comp(ll i, ll j){

ll x1,y1,x2,y2;
x1 = iotime[i].x;
y1 = iotime[i].y;
x2 = iotime[j].x;
y2 = iotime[j].y;

ll det = x1*y2-x2*y1;

if(det == 0){
    return io[i] > io[j];
}

else{
    return det < 0;
}
}

bool inbounds(ll x, ll y){

ll x1,x2,y1,y2;
x1 = min(X1.x,X2.x);
x2 = max(X1.x,X2.x);
y1 = min(X1.y,X2.y);
y2 = max(X1.y,X2.y);
return x >= x1 && x <= x2 && y >= y1 && y <= y2;

}

bool sinbounds(ll x, ll y){

ll x1,x2,y1,y2;
x1 = min(X1.x,X2.x);
x2 = max(X1.x,X2.x);
y1 = min(X1.y,X2.y);
y2 = max(X1.y,X2.y);
return x > x1 && x < x2 && y > y1 && y < y2;

}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;

    cin >> a >> b >> c >> d;
    X1.x = a;
    X1.y = b;
    X2.x = c;
    X2.y = d;
    bool nope = 0;
    for(ll c1 = 0; c1 < n; c1++){

        cin >> a >> b >> c >> d;
        pti x;
        pti v;
        x.x = a;
        x.y = b;
        v.x = c;
        v.y = d;
        X.push_back(x);
        V.push_back(v);

        vector<pti> now;

        if(c == 0 && d == 0){

            if(sinbounds(a,b)){

                pti x1,x2;
                x1.x = 0;
                x1.y = 1;
                x2.x = big*big;
                x2.y = 1;
                iotime.push_back(x1);
                iotime.push_back(x2);
                io.push_back(0);
                io.push_back(1);
                ind.push_back(ind.size());
                ind.push_back(ind.size());

            }
            else{
                nope = 1;
            }

        }
        else{
            pti time1 = timex(c1 , X1.x , X1.y, X2.y);

            if(time1.x * time1.y >= 0){

                bool yes = 1;
                for(ll c2 = 0; c2 < now.size(); c2++){
                    ll x1,x2,y1,y2;
                    x1 = time1.x;
                    y1 = time1.y;
                    x2 = now[c2].x;
                    y2 = now[c2].y;
                    if(x1*y2 - x2*y1 == 0)yes = 0;
                }

                if(yes){
                    iotime.push_back(time1);
                    ind.push_back(ind.size());
                    now.push_back(time1);
                }
            }

            time1 = timex(c1 , X2.x , X1.y, X2.y);
            if(time1.x * time1.y >= 0){

               bool yes = 1;
                for(ll c2 = 0; c2 < now.size(); c2++){
                    ll x1,x2,y1,y2;
                    x1 = time1.x;
                    y1 = time1.y;
                    x2 = now[c2].x;
                    y2 = now[c2].y;
                    if(x1*y2 - x2*y1 == 0)yes = 0;
                }

                if(yes){
                    iotime.push_back(time1);
                    ind.push_back(ind.size());
                    now.push_back(time1);
                }
            }

            time1 = timey(c1 , X1.y , X1.x, X2.x);
            if(time1.x * time1.y >= 0){
                bool yes = 1;
                for(ll c2 = 0; c2 < now.size(); c2++){
                    ll x1,x2,y1,y2;
                    x1 = time1.x;
                    y1 = time1.y;
                    x2 = now[c2].x;
                    y2 = now[c2].y;
                    if(x1*y2 - x2*y1 == 0)yes = 0;
                }

                if(yes){
                    iotime.push_back(time1);
                    ind.push_back(ind.size());
                    now.push_back(time1);
                }
            }

            time1 = timey(c1 , X2.y , X1.x, X2.x);
            if(time1.x * time1.y >= 0){
                bool yes = 1;
                for(ll c2 = 0; c2 < now.size(); c2++){
                    ll x1,x2,y1,y2;
                    x1 = time1.x;
                    y1 = time1.y;
                    x2 = now[c2].x;
                    y2 = now[c2].y;
                    if(x1*y2 - x2*y1 == 0)yes = 0;
                }

                if(yes){
                    iotime.push_back(time1);
                    ind.push_back(ind.size());
                    now.push_back(time1);
                }
            }


            if(now.size() > 2)cerr << "WTF";
            if(now.size() < 2){
                if(now.size() == 1 && inbounds(a,b)){
                    time1.x = 0;
                    time1.y = 1;
                    now.push_back(time1);
                    iotime.push_back(time1);
                    ind.push_back(ind.size());
                }
                else{
                    nope = 1;
                }
            }
            if(now.size() == 2){

                //cout << now[0].x << " " << now[0].y << " - " << now[1].x << " " << now[1].y << "  kjh\n";

                if(now[0].x * now[1].y < now[1].x * now[0].y){
                    io.push_back(0);
                    io.push_back(1);
                }
                else{
                    io.push_back(1);
                    io.push_back(0);
                }
            }

        }
        //cout << now.size() << "\n";
    }

    if(nope){
        cout << -1 << "\n";
    }
    else{

        for(ll c1 = 0; c1 < ind.size(); c1++){
            ld ans = ld(iotime[ind[c1]].x) / ld(iotime[ind[c1]].y);
            //cout << c1 << " " << ans << " - " << io[c1] << "\n";
        }

        sort(ind.begin() , ind.end() , comp);

        for(ll c1 = 0; c1 < ind.size(); c1++){
           // cout << ind[c1] << " ";
        }

        ll inc = 0;
        ld ans = 0;
        for(ll c1 = 0; c1 < n; c1++){

            if(io[ind[c1]] == 1)nope = 1;

            ans = ld(iotime[ind[c1]].x) / ld(iotime[ind[c1]].y);

            //cout << ans << " " << io[ind[c1]] << "\n";

        }

        if(nope){
            cout << -1 << "\n";
        }
        else{
            cout << setprecision(18) << ans << "\n";
        }
    }

    return 0;
}