#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    string sol;
    int pozicije[n]={};
    int tr=0;
    int counter=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            tr++;
        }
        else
        {
            if(tr>0&&counter<k/2)
            {
                tr--;
                pozicije[i]=1;
                counter++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='('&&counter>0)
        {
            counter--;
            sol+='(';
        }
        else
        {
            if(pozicije[i]==1)
            {
                sol+=')';
            }
        }
    }
    cout << sol << endl;;
    return 0;
}