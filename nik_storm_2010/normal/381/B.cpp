#include<iostream>
#include<vector>

using namespace std;
const int N = 200000;
const int M = 10000;

vector <int> a, b;
int cnt[M];

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = M; i >= 0; i--) if (cnt[i] != 0)
    {
        a.push_back(i);
        for (int j = i - 1; j >= 0; j--)
        {
            if (cnt[j] != 0) a.push_back(j);
            if (cnt[j] > 1) b.push_back(j);
        }
        break;
    }
    cout << a.size() + b.size() << endl;
    for (int i = a.size() - 1; i >= 0; i--) cout << a[i] << " ";
    for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
    return 0;
}