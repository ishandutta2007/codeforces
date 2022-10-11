// Not my code: https://codeforces.com/blog/entry/107328
 
#include <algorithm>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#define I int
#define itn int
#define cha char
#define endl "\n"
#define sz size()
#define st set<I>
#define ff first()
#define ss second()
#define mian() main()
#define map map<I, I>
#define vec vector<I>
#define pb push_back()
#define solver solve()
#define vch vector<ch>
#define vl vector<ll>
#define pii pair<I, I>
#define pll pair<ll, ll>
#define By cin.tie(NULL);
#define vll vector <ll, ll>
#define Edmond cout.tie(NULL);
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Code ios_base::sync_with_stdio(false);
using ull = unsigned long long;
using ld = long double;
using ll = long long;
using db = double;
using l = long;
using namespace std;
 
void solve()
{
    I n;
    ll a = 1;
    cin >> n;
    for (int i = 0; i < 5; i++) {
        a *= n - i;
    }
    double b = pow(a, 2);
    //pow(b, 10);
    a = b / 120;
    cout << a;
}
 
 
int mian()
{
    Code By Edmond
        /*I t; cin >> t;
    while (t--)*/
        solver;
    return 0;
}