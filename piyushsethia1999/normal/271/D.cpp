#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
struct alpha{
	alpha* next[26];
};
alpha *getnode() {
	alpha *temp = new alpha;
	for (int i = 0; i < 26; ++i)
	{
		temp->next[i] = NULL;
	}
	return temp;
}
int main()
{
	string s;
	cin>>s;
	string s2;
	cin>>s2;
	int k;
	cin>>k;
	bool b[26] = {false};
	for (int i = 0; i < 26; ++i)
	{
		if(s2[i] == '0')
			b[i] = true;
	}
	alpha *root = getnode();
	int l = s.size();
	int total = 0;
	for (int i = 0; i < l; ++i)
	{
		alpha *curr = root;
		int totalbad = 0;
		for (int j = i; j < l; ++j)
		{
			if(b[s[j] - 'a'])
				totalbad++;
			if(totalbad > k) {
				break;
			}
			if(curr->next[s[j]-'a'] == NULL){
				curr->next[s[j]-'a'] = getnode();
				total++;
			}
			curr = curr->next[s[j] - 'a'];
		}
	}
	cout<<total;
}