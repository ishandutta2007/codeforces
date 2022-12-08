#include <cstdio>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

const int MAXK=27;
const int MAXL=1000111;

int unCode(char c){
	return c-'a'+1;
}

char enCode(int a){
	return (char)(a+'a'-1);
}

int T;

int K;
int L;
char input[MAXL];
int Id[MAXL], A[MAXL], B[MAXL];
int Val[MAXK];
bool Vis[MAXK];

void Clear(){
	vector<int> Num;
	for(int i=1;i<=K;++i)	if(!Vis[i])	Num.push_back(i);
	for(int i=1, j=0, s=Num.size();i<=K;++i){
		if(!Val[i]){
			assert(j<s);
			Val[i]=Num[j];
			++j;
		}
	}
}

bool Deal_Left(int at){
	if(at>L)	return true;
	int &v=Val[Id[at]];
	if(v){
		if(v>A[at]){
			Clear();
			return true;
		}
		if(v<A[at])	return false;
		return Deal_Left(at+1);
	}
	for(int i=A[at]+1;i<=K;++i){
		if(!Vis[i]){
			v=i;Vis[v]=true;
			Clear();
			return true;
		}
	}
	if(Vis[A[at]])	return false;
	v=A[at];Vis[v]=true;
	return Deal_Left(at+1);
}

bool Deal_Right(int at){
	if(at>L)	return true;
	int &v=Val[Id[at]];
	if(v){
		if(v<B[at]){
			Clear();
			return true;
		}
		if(v>B[at])	return false;
		return Deal_Right(at+1);
	}
	for(int i=B[at]-1;i;--i){
		if(!Vis[i]){
			v=i;Vis[v]=true;
			Clear();
			return true;
		}
	}
	if(Vis[B[at]])	return false;
	v=B[at];Vis[v]=true;
	return Deal_Right(at+1);
}

bool Deal(int at){
	if(at>L)	return true;
	if(A[at]==B[at]){
		if(Val[Id[at]]){
			if(Val[Id[at]]==A[at])
				return Deal(at+1);
			return false;
		}
		if(Vis[A[at]])	return false;
		Val[Id[at]]=A[at];Vis[A[at]]=true;
		return Deal(at+1);
	}
	if(A[at]>B[at])	return false;
	int &v=Val[Id[at]];
	if(!v){
		for(int i=A[at]+1;i<B[at];++i){
			if(!Vis[i]){
				v=i;Vis[i]=true;Clear();
				return true;
			}
		}
		bool may=(!Vis[A[at]])||(!Vis[B[at]]);
		if(!may)	return false;
		int TmpVal[MAXK];
		bool TmpVis[MAXK];
		for(int i=1;i<=K;++i){
			TmpVal[i]=Val[i];
			TmpVis[i]=Vis[i];
		}
		if(!Vis[A[at]]){
			v=A[at];Vis[v]=true;
			if(Deal_Left(at+1))	return true;
		}
		for(int i=1;i<=K;++i){
			Val[i]=TmpVal[i];
			Vis[i]=TmpVis[i];
		}
		if(!Vis[B[at]]){
			v=B[at];Vis[v]=true;
			if(Deal_Right(at+1))	return true;
		}
		return false;
	}
	if(v==A[at])	return Deal_Left(at+1);
	if(v==B[at])	return Deal_Right(at+1);
	if(v<A[at] || v>B[at])	return false;
	Clear();return true;
}

int main(){
	
	scanf("%d", &T);
	
	while(T--){
		
		scanf("%d", &K);
		
		for(int i=1;i<=K;++i)	Val[i]=0;
		for(int i=1;i<=K;++i)	Vis[i]=false;
		
		scanf("%s", input);
		L=strlen(input);
		for(int i=1;i<=L;++i)	Id[i]=unCode(input[i-1]);
		
		scanf("%s", input);
		for(int i=1;i<=L;++i)	A[i]=unCode(input[i-1]);
		
		scanf("%s", input);
		for(int i=1;i<=L;++i)	B[i]=unCode(input[i-1]);
		
		if(!Deal(1))	puts("NO");
		else{
			Clear();
			puts("YES");
			for(int i=1;i<=K;++i)	printf("%c", enCode(Val[i]));
			puts("");
		}
		
	}
	
	return 0;
}