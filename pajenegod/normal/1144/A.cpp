#include <bits/stdc++.h>
using namespace std;

//Lolboyyyy's code

int main()
{
    int n, i;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        vector <int> arr;
        for (i = 0; i < s.size(); i++)
            arr.push_back(s[i] - 'a');
        
        sort(arr.begin(), arr.end());
        
        for (i = 0; i < s.size()-1; i++)
        {
            if (arr[i] + 1 != arr[i+1])
                break;
        }
        
        if (i < s.size()-1)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
}