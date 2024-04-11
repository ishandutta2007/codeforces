    #include <bits/stdc++.h>
     
    using namespace std;
     
    bool prime[500007];
    int mind[500007];
    int res[500007];
    vector <int> kolejka;
    int main()
    {
        int n,p=0,l=0;
        cin>>n;
        for(int i=2;i<=n/2;i++)
        {
            if(!prime[i])
            {
                for(int j=2*i;j<=n;j+=i)
                {
                    prime[j]=1;
                }
            }
        }
        for(int i=2;i<=250000;i++)
        {
            if(!prime[i])
            {
                for(int j=2*i;j<=n;j+=i)
                {
                    if(mind[j]==0) mind[j]=i;
                }
            }
        }
        for(int i=2;i<=n;i++)
        {
            if(mind[i]==0) kolejka.push_back(1);
            else kolejka.push_back(i/mind[i]);
        }
        sort(kolejka.begin(),kolejka.end());
        for(int i=0;i<kolejka.size();i++) cout<<kolejka[i]<<" ";
     
     
     
        return 0;
    }