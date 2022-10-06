#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        int N;
        cin >> N;
        unordered_map<int,int> m;
        vec<int> C(N);
        for(int i=0;i<N;i++){
            cin >> C[i];
            m[C[i]]++;
        }
        vec<P> cnt;
        int inf = 1e9;
        int mi = inf;
        unordered_map<int,int> m2;
        for(auto& x:m){
            m2[x.second]++;
            mi = min(mi,x.second);
        }
        for(auto& x:m2) cnt.emplace_back(x.first,x.second);
        int ans = inf;
        for(int s=2;s<=mi+1;s++){
            int now = 0;
            bool ok = true;
            for(auto& x:cnt){
                int cc = 0;
                int sho = x.first / s;
                int mo = x.first % s;
                if (mo == 0) {
                    cc = sho;
                }
                else if (mo == s - 1) {
                    cc = sho + 1;
                }
                else {
                    if (s - 1 - mo > sho) ok = false;
                    else {
                        cc = sho + 1;
                    }
                }
                now += cc * x.second;
            }
            if(ok) ans = min(ans,now);
        }
        cout << ans << endl;
    }
}