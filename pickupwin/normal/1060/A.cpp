#include <cstdio>
#include <cstring>

int N;
char input[111];
int Cnt8, Cnt;
int Ans=0;

int main(){
	
	scanf("%d", &N);
	scanf("%s", input);
	
	for(int i=0;i<N;++i)
		if(input[i]=='8')	++Cnt8;
	
	Cnt=N-Cnt8;
	
	while(true){
		if(!Cnt8)	break;
		--Cnt8;
		if(Cnt>=10)	{Cnt-=10;++Ans;}
		else{
			if(Cnt8+Cnt>=10){
				/*
				Cnt=0;
				Cnt8-=(10-Cnt);
				*/
				Cnt8-=(10-Cnt);
				Cnt=0;
				++Ans;
			}
			else	break;
		}
	}
	
	printf("%d\n", Ans);
	
	return 0;
}