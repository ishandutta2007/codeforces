#include <bits/stdc++.h>

using namespace std;

string f[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve",
                "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
                
string g[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main() {
    int n;
    scanf("%d", &n);
    if (n < 20) cout << f[n] << endl; else
    if (n % 10 == 0) cout << g[n / 10] << endl; else
    cout << g[n / 10] + "-" + f[n % 10] << endl;
}