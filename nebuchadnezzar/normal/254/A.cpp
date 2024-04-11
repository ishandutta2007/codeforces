#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, num;
vector <int> mas[5001];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n * 2; ++i)
    {
        cin >> num;
        mas[num].push_back(i);
    }
    //cout << "@";
    for (int i = 0; i < 5001; ++i)
    {
        
        if(mas[i].size() % 2 != 0)
        {
            cout << "-1";
            return 0;
        }
    }
    for (int i = 0; i < 5001; ++i)
    {
        int s = mas[i].size();
        //cout << s << endl;
        for (int j = 0; j < s / 2; ++j)
        {
            //cout << j << " ";
            cout << mas[i].back() + 1 << " ";
            mas[i].pop_back();
            cout << mas[i].back() + 1 << "\n";
            mas[i].pop_back();
        }
    }
    return 0;
}