#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair

const int MAXN = 1e6;
int h = 1;
int cnt[MAXN];
map<int,int>test;

int hashval(int sk){
	if(test[sk]==0){
		test[sk] = h;
		h++;
	}
	return test[sk];
}

int main(){
	int n;
	scanf("%i",&n);
	int a;
	for(int j = 0;j<n;j++){
		scanf("%i",&a);
		cnt[hashval(a)]++;
	}
	int m;
	cin >> m;
	int audio[m],lang[m];
	for(int j = 0;j<m;j++){
		scanf("%i",&audio[j]);
		audio[j] = hashval(audio[j]);
	}
	for(int j = 0;j<m;j++){
		scanf("%i",&lang[j]);
		lang[j] = hashval(lang[j]);
	}
	int cinema = 0;
	int l = -1,r = -1;
	for(int j = 0;j<m;j++){
		if(cnt[audio[j]]>l||(cnt[audio[j]] ==l&&cnt[lang[j]]>r)){
			cinema = j+1;
			l = cnt[audio[j]];
			r = cnt[lang[j]];
		}
	}
	printf("%i\n",cinema);
	return 0;
}