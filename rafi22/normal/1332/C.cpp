    #include <bits/stdc++.h>
     
    using namespace std;
     
    int ile[28];
    void clea()
    {
        for(int i=0;i<27;i++) ile[i]=0;
    }
     
    int main()
    {
        int n,d,k;
        int wyn,it,maxi=0,maxi1;
        string str;
        cin>>n;
        unordered_map <char,int> mapa;
        mapa.reserve(300007);
        for(int i=0;i<n;i++)
        {
            wyn=0;
            it=0;
            cin>>d>>k;
            char tab[d/k][k];
            cin>>str;
            for(int j=0;j<d/k;j++)
            {
     
                for(int l=0;l<k;l++)
                {
                    tab[j][l]=str[it];
                    it++;
                }
            }
            for(int l=0;l<k/2;l++)
            {
                maxi=0;
                clea();
                for(int j=0;j<d/k;j++)
                {
                    ile[tab[j][l]-97]++;
                    //cout<<tab[j][l]<<" ";
                    maxi=max(maxi, ile[tab[j][l]-97]);
                }
              //  cout<<endl;
                for(int j=0;j<d/k;j++)
                {
                    ile[tab[j][k-l-1]-97]++;
                    //cout<<tab[j][k-l-1]<<" ";
                    maxi=max(maxi, ile[tab[j][k-l-1]-97]);
                }
                //cout<<endl;
     
                wyn+=2*d/k-maxi;
            }
            if(k%2==1)
            {
                maxi=0;
                clea();
                for(int j=0;j<d/k;j++)
                {
                    ile[tab[j][k/2]-97]++;
                    //cout<<tab[j][l]<<" ";
                    maxi=max(maxi, ile[tab[j][k/2]-97]);
                }
                //cout<<maxi<<endl;
                wyn+=d/k-maxi;
            }
            cout<<wyn<<endl;
        }
        return 0;
    }