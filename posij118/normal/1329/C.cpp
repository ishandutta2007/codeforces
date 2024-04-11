#include <bits/stdc++.h>
using namespace std;

int inv[(1 << 20)];
bool flag[(1 << 20)];
vector<int> last;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    fill(flag, flag + (1 << 20), 0);
    fill(inv, inv + (1 << 20), -1);

    while(t--){
        int h, g;
        long long ans = 0;
        cin >> h >> g;

        pair<int, vector<int> > hp [(1 << h)];
        int ma[(1 << h)];
        fill(ma, ma + (1 << h), 0);

        for(int x: last){
            inv[x] = -1;
            flag[x] = 0;
        }

        last.resize(0);

        for(int i = 1; i<(1 << h); i++){
            cin >> hp[i].first;
            inv[hp[i].first] = i;
            last.push_back(hp[i].first);

            if(i >= (1 << (h - 1))){
                hp[i].second.push_back(hp[i].first);
            }
        }

        for(int i = (1 << (h - 1)) - 1; i>=1; i--){
            hp[i].second = hp[2*i].second;
            for(int x: hp[2*i + 1].second){
                hp[i].second.push_back(x);
            }
            hp[i].second.push_back(hp[i].first);
            ma[i] = max(ma[2*i], ma[2*i + 1]);
            int mi = 1e9 + 7;

            if(i < (1 << g)){
                for(auto x: hp[i].second){
                    if(x > ma[i]) mi = min(mi, x);
                }
                ans += mi;
                flag[mi] = 1;
                ma[i] = mi;
            }
        }

        cout << ans << endl;

        sort(last.begin(), last.end());
        reverse(last.begin(), last.end());
        for(auto i: last){
            if(inv[i] > 0 && flag[i] == 0){
                int pos = inv[i];
                cout << pos << " ";

                while(pos < (1 << (h - 1))){
                    if(hp[2*pos].first == 0 && hp[2*pos + 1].first == 0){
                        hp[pos].first = 0;
                        break;
                    }

                    else if(hp[2*pos].first > hp[2*pos + 1].first){
                        int j = hp[2*pos].first;
                        swap(inv[i], inv[j]);
                        swap(hp[pos].first, hp[2*pos].first);
                        pos = 2*pos;
                    }

                    else if(hp[2*pos].first < hp[2*pos + 1].first){
                        int j = hp[2*pos + 1].first;
                        swap(inv[i], inv[j]);
                        swap(hp[pos].first, hp[2*pos + 1].first);
                        pos = 2*pos + 1;
                    }

                    if(pos >= (1 << (h - 1))) hp[pos].first = 0;
                }

                inv[i] = -1;
            }
        }

        cout << endl;

    }

}