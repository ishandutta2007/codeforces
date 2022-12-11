#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define f first
#define s second
#define t abs


int main(){

    int s[3];
    cin >> s[0] >> s[1] >> s[2];
    sort(s,s+3);
    cout << (s[2]-s[1]) + (s[1]-s[0]);
    return 0;
}