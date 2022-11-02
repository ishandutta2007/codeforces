#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
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

bool inrect(vector<vec> a, vec C) {
    vec P, N, F;
    P = a[0];
    if (C == P) {
    	return true;
    }
    vec luch(1e9, 1e9 + 1);
    F = P;
    int count = 0;
    for (int i = 1; i < 4; ++i) {
        N = a[i];
        if (in(C, P, N)) {
        	return true;
        }
        vec ob = vec(C, P), oa = vec(C, N), op = luch;
        if (in_angle(op, oa, ob)) ++count;
        P = N;
    }
    if (in(C, P, F)) {
    	return true;
    }
    vec ob = vec(C, P), oa = vec(C, F), op = luch;
    if (in_angle(op, oa, ob)) ++count;
    if (count % 2 == 1) return true;
    else return false;
}
 
int main() {
	vector<vec> arr(4), brr(4);
	for (auto &i : arr) cin >> i.x >> i.y;
	for (auto &i : brr) cin >> i.x >> i.y;
	for (ll x = -200; x < 200; ++x)
		for (ll y = -200; y < 200; ++y)
			if (inrect(arr, vec(x, y)) && inrect(brr	, vec(x, y))) {
				cout << "YES";
				return 0;
			}
	cout << "NO";
	return 0;
}