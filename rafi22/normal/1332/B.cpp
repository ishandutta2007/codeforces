    #include <bits/stdc++.h>
     
    using namespace std;
     
    int rep[11];
     
    int main()
    {
        int t,a;
        cin>>t;
        vector <int> vec;
        set <int> se;
        int tab[11]={2 ,3 ,5 ,7 ,11 ,13 ,17 ,19 ,23 ,29 ,31};
        int it=1;
     
        for(int i=0;i<t;i++)
        {
            vec.clear();
            it=1;
            for(int k=0;k<11;k++) rep[k]=0;
            int n;
            cin>>n;
            for(int k=0;k<n;k++)
            {
                cin>>a;
                for(int j=0;j<11;j++)
                {
                    if(a%tab[j]==0)
                    {
                        if(rep[j]>0)
                            vec.push_back(rep[j]);
                        else
                        {
                            rep[j]=it++;
                            vec.push_back(rep[j]);
                        }
                        break;
                    }
                }
            }
            cout<<it-1<<endl;
            for(int j=0;j<vec.size();j++) cout<<vec[j]<<" ";
            cout<<endl;
        }
        return 0;
    }