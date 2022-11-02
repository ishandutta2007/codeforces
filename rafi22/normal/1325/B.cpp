    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t,n,a;
        set <int> zbior;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            zbior.clear();
            cin>>n;
            for(int i=0;i<n;i++)
            {
                cin>>a;
                zbior.insert(a);
            }
            cout<<zbior.size()<<endl;
        }
        return 0;
    }