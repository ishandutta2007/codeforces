#include<bits/stdc++.h>
using namespace std;
inline int scan(){
    /*char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }*/
    int x;
    scanf("%d",&x);
    return x;
}
bool ispal(vector<char> x){
    int n=x.size();
    for(int i=0;i<n/2;i++){
        if(x[i]!=x[n-i-1]){
            return 0;
        }
    }
    return 1;
}
int main(){
    vector<char> s;
    char a[20]={NULL};
    scanf("%s",a);
    int n=strlen(a);
    for(int i=0;i<n;i++){
        s.push_back(a[i]);
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<26;j++){
            char temp='a'+j;
            vector<char> t;
            t=s;
            t.insert(t.begin()+i,temp);
            if(ispal(t)){
                for(int i=0;i<=n;i++){
                    printf("%c",t[i]);
                }
                return 0;
            }
        }
    }
    printf("NA");
}