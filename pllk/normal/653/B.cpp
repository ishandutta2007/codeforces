#include <iostream>
#include <map>

using namespace std;

int n;
string a[40], b[40];
int c;

map<string,bool> d;
map<string,string> q;

bool ok(string s) {
    if (d.count(s)) return d[s];
    bool t = false;
    for (int i = 0; i < s.size()-1; i++) {
        if (i != 0) break;
        string e = s.substr(i,2);
        if (q.count(e)) {
            string u = s.substr(0,i)+q[e]+s.substr(i+2);
            //cout << s << " " << i << " " << e << "\n";
            //cout << u << "\n";
            if (ok(u)) {t = true; break;}
        }
    }
    d[s] = t;
    return t;
}

void haku(string s) {
    if (s.size() == n) {
        if (ok(s)) c++;
        return;
    }
    haku(s+"a");
    haku(s+"b");
    haku(s+"c");
    haku(s+"d");
    haku(s+"e");
    haku(s+"f");
}

int main() {
    int qq;
    cin >> n >> qq;
    for (int i = 1; i <= qq; i++) {
        cin >> a[i] >> b[i];
        q[a[i]] = b[i];
    }
    d["a"] = 1;
    d["b"] = 0;
    d["c"] = 0;
    d["d"] = 0;
    d["e"] = 0;
    d["f"] = 0;
    haku("");
    cout << c << "\n";
}