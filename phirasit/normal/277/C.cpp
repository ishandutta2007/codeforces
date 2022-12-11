#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

map<int, vector<pii> > hor, ver;

int n, m, k;

vector<int> data;

int solve(vector<pii> x, int a, int b) {
    if(x.empty()) return b - a;
    data.clear();
    for(pii &p : x) {
        data.push_back(p.first);
        data.push_back(-p.second);
    }
    sort(data.begin(), data.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });
    int ans = 0, cnt = 0;
    while(!data.empty() and abs(data.back()) > b) data.pop_back();
    if(data.empty()) return b - a;
    for(int i = 0;i < data.size();i++) {
        if(cnt == 0) {
            ans += abs(data[i]) - (i > 0 ? abs(data[i-1]) : 0);
        }
        cnt += (data[i] >= 0 ? 1 : -1);
    }
    if(cnt == 0) ans += b - abs(data.back());
    return ans;
}
int main() {

    ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    for(int i = 0;i < k;i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2) {
            hor[x1].push_back(pii(min(y1, y2), max(y1, y2)));
        }else if(y1 == y2) {
            ver[y1].push_back(pii(min(x1, x2), max(x1, x2)));
        }
    }

    int ans = ((n-1 - hor.size()) % 2 ? m : 0) ^ ((m-1 - ver.size()) % 2 ? n : 0);
    for(auto& it : hor) {
        ans ^= solve(it.second, 0, m);
    }
    for(auto& it : ver) {
        ans ^= solve(it.second, 0, n);
    }

    if(ans == 0) {
        cout << "SECOND\n";
        return 0;
    }

    cout << "FIRST\n";

    bool found = false;
    for(auto& x : hor) {
        int lf = solve(x.second, 0, m);
        if((lf ^ ans) <= lf) {
            found = true;
            int rem = lf - (lf ^ ans);
            int a = 0, b = m;
            while(a < b) { 
                int mid = (a + b) / 2;
                if(solve(x.second, 0, mid) < rem) {
                    a = mid + 1;
                }else {
                    b = mid;
                }
            }
            cout << x.first << " " << 0 << " " << x.first << " " << a << "\n";
            break;
        }   
    }
    if(!found) {
        for(auto &x : ver) {
            int lf = solve(x.second, 0, n);        
            if((lf ^ ans) <= lf) {
                found = true;
                int rem = lf - (lf ^ ans);
                int a = 0, b = n;
                while(a < b) { 
                    int mid = (a + b) / 2;
                    if(solve(x.second, 0, mid) < rem) {
                        a = mid + 1;
                    }else {
                        b = mid;
                    }
                }
                cout << 0 << " " << x.first << " " << a << " " << x.first << "\n";
                break;
            }
        }
    }
    if(!found and (ans ^ m) <= m) {
        for(int i = 1;i < n;i++) {
            if(hor.find(i) != hor.end()) continue;
            int lf = m;
            if((lf ^ ans) <= lf) {
                found = true;
                int rem = lf - (lf ^ ans);
                int a = 0, b = m;
                while(a < b) { 
                    int mid = (a + b) / 2;
                    if(solve(hor[i], 0, mid) < rem) {
                        a = mid + 1;
                    }else {
                        b = mid;
                    }
                }
                cout << i << " " << 0 << " " << i << " " << a << "\n";
                break;
            }else {
                break;
            }
        }
    }
    if(!found and (ans ^ n) <= n) {
        for(int i = 1;i < m;i++) {
            if(ver.find(i) != ver.end()) continue;
            int lf = n;
            if((lf ^ ans) <= lf) {
                found = true;
                int rem = lf - (lf ^ ans);
                int a = 0, b = n;
                while(a < b) { 
                    int mid = (a + b) / 2;
                    if(solve(ver[i], 0, mid) < rem) {
                        a = mid + 1;
                    }else {
                        b = mid;
                    }
                }
                cout << 0 << " " << i << " " << a << " " << i << "\n";
                break;
            }else {
                break;
            }
        }
    }
    return 0;
}