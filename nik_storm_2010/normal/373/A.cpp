#include<iostream>
#include<string>

using namespace std;
const int N = 5;
const int M = 256;

char a[N][N];
int cnt[M];

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cin >> a[i][j];
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cnt[a[i][j]]++;
    string ans = "YES";
    for (int i = 0; i < M; i++) if (i != '.' && cnt[i] > 2 * k) ans = "NO";
    cout << ans << endl;
    return 0;
}