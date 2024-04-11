#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair

const int N = (int)1e5 + 10;
const int BLOCK = 97;
bool pr[N];
bool active[N];

int playx;

int n;

int get(char typ, int d){
    cout << typ << " " << d << endl;
    int res;
    cin >> res;
    return res;
}

int main(){
    cin >> n;
    for(int i = 2; i < N ; i ++ ){
        for(int j = i + i; j < N; j += i)
            pr[j] = true;
    }
    for(int i = 1; i <= n; i ++ )
        active[i]=true;
    int cnt = n;
    vector<int> pp, qk;
    int gg;
    int shl;
    for(int i = 2; i <= n ; i ++ ){
        if(!pr[i]){
            int sol;
            sol = get('B', i);
            shl = 0;
            for(int j = i ; j < N; j += i){
                shl += active[j];
                if(active[j] == true)
                    cnt -= 1;
                active[j]=false;
            }
            if(sol != shl){
                pp.push_back(i);
            }
            else{
                if(pp.empty())
                    qk.push_back(i);
                if(qk.size() == BLOCK){
                    gg = get('A', 1);

                    if(gg != cnt){
                        for(auto x : qk){
                            gg = get('B', x);
                            if(gg == 1){
                                pp.push_back(x);
                                break;
                            }
                        }

                    }
                    qk.clear();

                }
            }
        }
    }
    for(auto x : qk){
        gg = get('B', x);
        if(gg == 1){
            pp.push_back(x);
        }
    }
    int answ = 1;
    int ds;
    int mx;
    for(auto y : pp){
        ds = y;
        mx = 1;
        while(ds <= n){
            gg = get('A', ds);
            if(gg == 0){
                ds /= y;
                break;
            }
            if((ds * 1ll * y) > n) break;
            ds *= y;
        }
        answ *= ds;
    }
    cout << "C " << answ << endl;

    return 0;
}