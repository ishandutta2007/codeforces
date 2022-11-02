#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;
 
int n;
vector<char> a, b;
int l, r;
bool rev = false;

void f(int num) {
    vector<char> temp;

    /*if (num == a.size()) {
        cout << "f_bad" << endl;
        cout << a.size() - num << endl;

        for(char i : a) 
            cout << i;
        cout << endl;

        for(int i = 0;i < a.size();i++)
            cout << a[i];
        cout << endl;

        for(int i = a.size() - 1;i >= 0;i--) 
            cout << a[i];
        cout << endl;


        cout << a.size() << " " << num << endl;
        for(int i = a.size() - 1;i >= (int)a.size() - num;i--) 
            cout << a[i];
        cout << endl;
    }*/


    for(int i = a.size() - 1;i >= (int)a.size() - num;i--) 
        temp.emplace_back(a[i]);

    /*if (num == a.size()) {
        cout << "mid" << endl;
    }*/

    for(int i = 0;i < (int)a.size() - num;i++)
        temp.emplace_back(a[i]);

    /*if (num == a.size()) {
        cout << "end" << endl;
    }*/

    a = temp;
}

void scan() {
    string s, t;
    cin >> n >> s >> t;

    for(char i : s) 
        a.emplace_back(i);
    for(char i : t) 
        b.emplace_back(i);

    l = n / 2;
    r = l - 1;
}

void solve() {
    scan();
    vector<int> res;

    
    /*for(char i : a) 
        cout << i;
    cout << endl;*/

    bool bad = false;

    while(r - l + 1 < n || rev) {
        char let = 0;
        if (!rev && l - 1 >= 0) let = b[l - 1];
        if (rev && r + 1 < n) let = b[r + 1];

        int id = n - 1;

        for(;id >= r - l + 1;id--) {
            if (a[id] == let) break;
        }

        if (let != 0 && id == r - l) {
            bad = true;
            break;
        }
        //if (r - l <= 0) {
            //what_is(id);
        //}

        if (let == 0) id = r - l + 1;

        f(n - id);
        res.emplace_back(n - id);

        //if (r - l <= 0) {
            /*for(char i : a) 
                cout << i;
            cout << endl;*/
        //}

        f(n - (n - id) - (r - l + 1));
        res.emplace_back(n - (n - id) - (r - l + 1));

        //if (r - l <= 0) {
            /*for(char i : a) 
                cout << i;
            cout << endl;*/
        //}

        if (let != 0) {
            if (rev) r++;
            else l--;
        }


        //if (r - l + 1 == n) cout << "bad" << endl;

        f(r - l + 1);
        res.emplace_back(r - l + 1);

        //if (r - l + 1 == n) cout << "good" << endl;

        //if (r - l <= 1) {
            /*for(char i : a) 
                cout << i;
            cout << endl;*/
        //}

        rev = !rev;

        //if (r - l <= 1) {
            //cout << l + 1 << " " << r + 1 << " " << rev << endl;
        //}
        //for(char i : a) 
        //    cout << i;

        //cout << endl;
    }

    if (bad) cout << -1;
    else {
        cout << res.size() << endl;
        for(int i : res) cout << i << " ";
    }

}



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}