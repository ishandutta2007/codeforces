#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")

#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define f first
#define s second

#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

ll sign(ll a) {
    if (a == 0) return 0;
    if (a > 0) return 1;
    return -1;
}
 
struct vec {
    ll x = 0, y = 0;
    vec() {
 
    }
    vec(ll x, ll y) {
        this->x = x;
        this->y = y;
    }  
    vec(vec a, vec b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    void mul(ll k) {
        x *= k;
        y *= k;
    }
};
 
istream& operator>>(istream& is, vec& a) {  
   is >> a.x >> a.y;
   return is;  
}
 
ostream& operator<<(ostream& os, vec a) {  
   os << a.x << ' ' << a.y << '\n';
   return os;  
}  
 
bool operator==(vec a, vec b) {
    return a.x == b.x && a.y == b.y;
}
 
ll operator*(vec a, vec b) {
    return a.x * b.x + a.y * b.y;
}
 
vec operator*(vec a, ll b) {
    return vec(a.x * b, a.y * b);
}
 
ll operator/(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}
 
vec operator-(vec a, vec b) {
    return vec(a.x - b.x, a.y - b.y);
}
 
vec operator+(vec a, vec b) {
    return vec(a.x + b.x, a.y + b.y);
}
 
ld len(vec a) {
    return sqrt(a * a);
}
 
bool in(ll x, ll a, ll b) {
    if (a > b) swap(a, b);
    return x >= a && x <= b;
}
 
bool in(vec c, vec a, vec b) {
    return in(c.x, a.x, b.x) && in(c.y, a.y, b.y) &&
    (c.x - a.x) * (b.y - c.y) == (b.x - c.x) * (c.y - a.y);
}
 
bool in_angle(vec op, vec oa, vec ob) {
    return sign(oa / op) >= 0 && sign(op / ob) >= 0 && sign(oa / ob) >= 0 ||
        sign(oa / op) <= 0 && sign(op / ob) <= 0 && sign(oa / ob) <= 0;
}

int n;
vector<vec> arr;

bool check(vec first, vec start) {
    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        vec newvec = vec(start, arr[i]);
        if (newvec / first == 0) used[i] = true;
    }
    vector<vec> newones;
    for (int i = 0; i < n; ++i)
        if (!used[i]) newones.pb(arr[i]);
    if (newones.size() <= 2) return true;
    vec check = vec(newones[0], newones[1]);
    for (int i = 2; i < newones.size(); ++i) {
        vec newvec = vec(newones[0], newones[i]);
        if (newvec / check != 0) return false;
    }
    return true;
}

int main() {
	FAST;
    cin >> n;
    arr = vector<vec> (n);
    for (auto &i : arr) cin >> i;
    if (n <= 4) {
        cout << "YES";
        return 0;
    }
    bool flag = true;
    vec first = vec(arr[0], arr[1]);
    int ptr;
    for (int i = 2; i < n; ++i) {
        vec newvec = vec(arr[0], arr[i]);
        if (first / newvec != 0) {
            flag = false;
            ptr = i;
            break;
        }
    }
    if (flag) {
        cout << "YES";
        return 0;
    }
    if (check(vec(arr[0], arr[1]), arr[0])) {
        cout << "YES";
        return 0;
    }
    if (check(vec(arr[0], arr[ptr]), arr[0])) {
        cout << "YES";
        return 0;
    }
    if (check(vec(arr[1], arr[ptr]), arr[1])) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}