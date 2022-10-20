#include <bits/stdc++.h>
using namespace std;
int main(){
	string s,t,u;
	vector<pair<char,int> > tp;
	int i,pos;
	cin>>s;
	t=u="";
	for(i=0;i<26;i++)
	{
		if(s.size()==0)
			break;
		pos=s.find(i+'a');
		if(pos!=-1)
		{
			while(t.size()!=0&&t[t.size()-1]<=i+'a')
			{
				u+=t[t.size()-1];
				t=t.substr(0,t.size()-1);
			}
			t+=s.substr(0,pos);
			u+=s[pos];
			s=s.substr(pos+1);
			i--;
		}
	}
	while(t.size()>0)
	{
		u+=t[t.size()-1];
		t=t.substr(0,t.size()-1);
	}
	cout<<u<<endl;
	return 0;
}
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabfjonyyqkgxvulzwjxchocuvimbtgzntkylpnkjcxnkodikjnyryvzmjyrrvncuqyxcpfqkyffuxpxddnjrpefqrhmwecxxtthhhksryrnmdhlddmdbwwcfuueqvs
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabfjnoyyqkgxvulzwjxchocuvimbtgzntkylpnkjcxnkodikjnyryvzmjyrrvncuqyxcpfqkyffuxpxddnjrpefqrhmwecxxtthhhksryrnmdhlddmdbwwcfuueqvs