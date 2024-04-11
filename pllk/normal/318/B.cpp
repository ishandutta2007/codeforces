#include <iostream>

#define ll long long int

using namespace std;

string s;

int main() {
    cin >> s;
    int p = s.length();
    int a = 0;
    ll b = 0;
    for (int i = 0; i < p-4; i++) {
        if (s[i]=='h'&&s[i+1]=='e'&&s[i+2]=='a'&&s[i+3]=='v'&&s[i+4]=='y') a++;
        if (s[i]=='m'&&s[i+1]=='e'&&s[i+2]=='t'&&s[i+3]=='a'&&s[i+4]=='l') b+=a;
    }
    cout << b << endl;
}