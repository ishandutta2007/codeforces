//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1000 * 100 + 100;
vector<int> *vec[maxn];
int ans[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n;
    map<int, int> cnt;
    cin >> n;
    int plused = 0;
    for (int i = 0; i < n + n; i++) {
        char op;
        cin >> op;
        if (op == '+') {
            cnt[0]++;
            if (!vec[0])
                vec[0] = new vector<int>;
            vec[0]->PB(plused++);
        }
        else {
            int num;
            cin >> num;
            auto it = cnt.lower_bound(num);
            if (it != cnt.begin()) {
                it--;
                ans[vec[it->L]->back()] = num;
                vec[it->L]->pop_back();
                if (it->R == 1)
                    cnt.erase(it);
                else
                    cnt[it->L]--;
            }
            else
                return cout << "NO\n", 0;

            int sum = 0;
            vector<int> *curvec = NULL;
            while (sz(cnt) and cnt.begin()->L < num) {
                sum += cnt.begin()->R;
                int id = cnt.begin()->L;
                if (curvec == NULL)
                    curvec = vec[id];
                else {
                    if (curvec->size() < vec[id]->size())
                        swap(curvec, vec[id]);
                    for (auto mem: *vec[id])
                        curvec->PB(mem);
                    delete vec[id];
                }
                vec[id] = NULL;
                cnt.erase(cnt.begin());
            }

            if (sum) {
                cnt[num] += sum;
                vec[num] = curvec;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
	return 0;
}