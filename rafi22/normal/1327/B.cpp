    #include <bits/stdc++.h>
     
    using namespace std;
     
    vector <int> doughter;
    deque <int> unmaried;
    bool ksiaze[100007];
     
    int main()
    {
        int t,n,k,a,poin=0;
        cin>>t;
        bool m;
        for(int i=0;i<t;i++)
        {
            cin>>n;
            for(int j=1;j<=n;j++)
            {
                cin>>k;
                m=0;
                for(int l=0;l<k;l++)
                {
                    cin>>a;
                    if(m==0)
                    {
                        if(ksiaze[a]==0)
                        {
                            m=1;
                            ksiaze[a]=1;
                        }
                    }
     
                }
                if(m==0) unmaried.push_back(j);
            }
     
            if(unmaried.size()>0)
            {
                cout<<"IMPROVE"<<endl;
                for(int j=1;j<=n;j++)
                {
                    if(ksiaze[j]==0)
                    {
                        cout<<unmaried[0]<<" "<<j<<endl;
                        break;
                        unmaried.pop_front();
                    }
                }
            }
            else
            {
                cout<<"OPTIMAL"<<endl;
            }
     
            unmaried.clear();
            for(int j=1;j<=n;j++) ksiaze[j]=0;
     
        }
        return 0;
    }