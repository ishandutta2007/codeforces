#include <bits/stdc++.h>
#define fora(i,a,b) for(int i=a,Wub=b;i<Wub;++i)
#define ford(i,a,b) for(int i=a,Wub=b;i>=Wub;--i)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define MAX 1000000
#define MOD 1073741824
using namespace std;
typedef long long ll;
 
vector<int> z_function(string& s){
	int l=0,r=0,n=s.size();
	vector<int> z(s.size(),0); // z[i] = max k: s[0,k) == s[i,i+k)
	fora(i,1,n){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}
string mer(string a, string b){
    int ta=a.size(),tb=b.size();
    string u = a+"$"+b;
    vector<int>x = z_function(u);
    reverse(x.begin(),x.end());
    string x1;
    int f=0;
    //cout<<u<<"->\n";
    fora(i,0,tb){
        //cout<<x[i]<<" ";
        if(x[i]==ta){
            return b;
        }
        if(x[i]==i+1){
            f=i+1;
        }
    }
    //cout<<"\n";
    x1=b.substr(0,tb-f)+a;
    return x1;
}
int prob(string a, string b, string c){
    string x=mer(a,b);
    x=mer(x,c);
    return x.size();
}
 
int main(){
    fio;
    string a,b,c;
    cin>>a>>b>>c;
    int mini=INT_MAX;
    //abc
    mini= min(mini, prob(a,b,c));
    //acb
    mini= min(mini, prob(a,c,b));
    //bac
    mini= min(mini, prob(b,a,c));
    //bca
    mini= min(mini, prob(b,c,a));
    //cab
    mini= min(mini, prob(c,a,b));
    //cba
    mini= min(mini, prob(c,b,a));
    cout<<mini<<endl;
}