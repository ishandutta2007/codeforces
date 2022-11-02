    #include <bits/stdc++.h>
     
    using namespace std;
     
     
    int main()
    {
        int t,n;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            cin>>n;
            int tab[n];
            for(int j=0;j<n;j++) cin>>tab[j];
            sort(tab,tab+n,greater<int>());
            for(int j=0;j<n;j++) cout<<tab[j]<<" ";
            cout<<endl;
        }
        return 0;
    }