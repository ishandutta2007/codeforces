    #include <bits/stdc++.h>
     
    using namespace std;
     
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        int n,mini,last=0;
        long long res,act=0,p;
        cin>>n;
        mini=n;
        res=0;
        int tab[n+1];
        for(int  i=1;i<=n;i++) cin>>tab[i];
        map <long long,int > mapa;
        map <long long,int > mapa1;
        mapa[0]++;
        for(int i=1;i<=n;i++)
        {
            act+=(long long)tab[i];
            //cout<<act<<endl;
           // cout<<act<<endl;
     
            if(mapa[act]>0)
            {
                last=max(last,mapa1[act]+1);
            }
     
            res+=(long long)i-(long long)last;
            mapa[act]++;
            mapa1[act]=i;
     
        }
       // mini++;
       cout<<res<<endl;
        return 0;
    }