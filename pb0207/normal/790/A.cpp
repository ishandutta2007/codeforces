    #include <cstdio>  
    #include <cstring>  
    #include <iostream>  
    using namespace std;  
    string s[60];  
    void Init(){  
        s[0]="Aa";  
        for(int i=1;i<26;i++){  
            s[i]=s[i-1];  
            s[i][1]++;  
        }  
        s[26]="Ba";  
        for(int i=27;i<=50;i++){  
            s[i]=s[i-1];  
            s[i][1]++;  
        }  
    }  
    int main(){  
        int n,k;  
        Init();  
        scanf("%d%d",&n,&k);  
        string ss;  
        for(int i=0;i<n-k+1;i++){  
            cin>>ss;  
            if(ss[0]=='N'){  
                //cout<<s[i]<<endl;  
                //cout<<s[i+k-1]<<endl<<endl;  
                s[i+k-1]=s[i];  
            }  
        }  
        for(int i=0;i<n;i++){  
            if(i!=0)  
                cout<<" ";  
            cout<<s[i];  
      
        }  
        cout<<endl;  
        return 0;  
    }