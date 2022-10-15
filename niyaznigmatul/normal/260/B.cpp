#include <cstdio>
#include <string>
#include <map>

using namespace std;
//using std::map;
//using std::string;

int ni() {
    int c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    int sg = 0;
    if (c == '-') {
        c = getchar();
        sg = 1;
    }
    int ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;

}

int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int s[123456];


int main() {
    int c = getchar();
    int n = 0;
    while (c > 32) {
        s[n++] = c;
        c = getchar();
    }
    map<string, int> q;
    for (int i = 0; i < n; i++) {
        if (i + 10 > n) break;
        int ok = 1;
        for (int j = 0; j < 10; j++) {
            if (j == 2 || j == 5) {
                if (s[i + j] != '-') ok = 0;
            } else if (s[i + j] < '0' || s[i + j] > '9') ok = 0;
        }
        if (!ok) continue;
        int day = s[i] * 10 + s[i + 1] - 11 * '0';
        int month = s[i + 3] * 10 + s[i + 4] - 11 * '0';
        int year = 0;
        for (int j = 6; j < 10; j++) year = year * 10 + s[i + j] - '0';
        if (year < 2013 || year > 2015) continue;
        if (month < 1 || month > 12) continue;
        if (day < 1 || day > d[month - 1]) continue;
        string z = "";
        for (int j = 0; j < 10; j++) z += s[i + j];
        q[z]++;
    }
    int best = -1;
    string ans = "BAD";
    for (map<string, int> :: iterator it = q.begin(); it != q.end(); ++it) {
        if (it->second > best) {
            best = it->second;
            ans = it->first;
        }
    }
    puts(ans.c_str());
}