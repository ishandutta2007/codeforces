#include<cstring>
#include<iostream>
using namespace std;

char x[200005],y[200005];
int ch[33];
string s;

int main(){
    memset(ch,-1,sizeof ch);
    int n,m;
    cin >> n >> m; cin >> s;
    for(int i=0; i<m; i++)cin >> x[i] >> y[i];
    for(int j=0; j<26; j++){
        char w='a'+j;
//          cout << w << endl;
        for(int i=0; i<m; i++){
            if(x[i]!=w&&y[i]!=w)continue;
            if(x[i]==y[i]&&x[i]==w)continue;
            if(x[i]==w)w=y[i];
            else if(y[i]==w)w=x[i];
        }
        ch[j]=w-'a';
//      cout << "######\n";
    }
    for(int i=0; i<n; i++){
        cout << (char)(ch[s[i]-'a']+'a');
    }cout << endl;
//  for(int i=0; i<26; i++)cout << (char)(i+'a') << " " << (char)(ch[i]+'a') << endl;
    return 0;
}