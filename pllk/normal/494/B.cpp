#include <iostream>
#include <vector>

#define ll long long
#define MM 1000000007

using namespace std;

string A, B;
string s;
int n;
int z[201010];

ll u[101010];
ll s1[101010];
ll d[101010];
ll s2[101010];

int main() {
    cin >> A >> B;
    s = B + "$" + A;
    n = s.size();
    int a = 0, b = 0;
    for (int i = 1; i < n; i++) {
        if (i > b) {
            z[i] = 0;
            for (int j = i; j < n; j++) {
                if (s[j-i] == s[j]) z[i]++;
                else break;
            }
        } else if (i+z[i-a] <= b) {
            z[i] = z[i-a];
        } else {
            z[i] = b-i+1;
            for (int j = b+1; j < n; j++) {
                if (s[j-i] == s[j]) z[i]++;
                else break;
            }
        }
        if (i+z[i]-1 > b) {
            a = i;
            b = i+z[i]-1;
        }
    }
    vector<int> v;
    for (int i = B.size()+1; i < s.size(); i++) {
        if (z[i] == B.size()) v.push_back(i-B.size()-1);
    }
    v.push_back(999999999);
    
    int N = A.size();
    int M = B.size();

    int j = -1;
    ll r = 0;
    for (int i = 0; i < N; i++) {
        while (v[j+1]+M-1 <= i) j++;
        if (j == -1) u[i] = 0;
        else {
            u[i] = v[j]+1;
            if (v[j] > 0) u[i] += s2[v[j]-1];
        }
        u[i] %= MM;
        r += u[i];
        r %= MM;
        if (i > 0) s1[i] = s1[i-1];
        s1[i] += u[i];
        s1[i] %= MM;
        if (i > 0) s2[i] = s2[i-1];
        s2[i] += s1[i];
        s2[i] %= MM;
    }

    cout << r << "\n";
}