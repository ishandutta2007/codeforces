    #include <iostream>
     
    using namespace std;
     
    int main()
    {
        int t;
        cin>>t;
        string str;
        for(int j=0;j<t;j++)
        {
            cin>>str;
            char last=str[0];
            int d=1,maxi=0;
            for(int i=1;i<str.size();i++)
            {
                if(str[i]==last) d++;
                else
                {
     
                    if(last=='L')
                        maxi=max(maxi,d);
                    d=1;
                    last=str[i];
                }
            }
            if(last=='L')
                maxi=max(maxi,d);
            cout<<maxi+1<<endl;
        }
        return 0;
    }