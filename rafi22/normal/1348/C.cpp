#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        int n,k;
        cin>>n>>k;
        string str;
        cin>>str;
        vector <int> litery;
        set <char> is;
        int ile[31];
        for(int i=0;i<=30;i++) ile[i]=0;
        for(int i=0;i<n;i++)
        {
            litery.push_back((int)str[i]);
            is.insert(str[i]);
            ile[str[i]-97]++;
        }
        sort(litery.begin(),litery.end());
        char st=*is.begin();
        if(litery[0]!=litery[k-1]) cout<<(char)litery[k-1];
        else if(is.size()==1)
        {
            for(int i=0;i<(int)ceil((double)n/(double)k);i++)
            {
                cout<<*is.begin();
            }

        }
        else if(is.size()==2&&ile[st-97]==k)
        {
            char nd=*++is.begin();
            for(int i=0;i<ile[st-97]/k;i++) cout<<st;
            int g;
            if(ile[nd-97]%k==0) g=ile[nd-97]/k;
            else g=ile[nd-97]/k+1;
            for(int i=0;i<g;i++)
            {
                cout<<nd;
            }
        }
        else
        {
            cout<<(char)litery[0];
            for(int i=k;i<n;i++) cout<<(char)litery[i];
        }
        cout<<endl;
    }
    return 0;
}