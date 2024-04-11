program storm;
uses math;
var G:array[1..105,1..105] of longint;
    used:array[1..105] of boolean;
    por:array[1..1000] of longint;
    k,i,sum1,sum2,n,sum:longint;



procedure inputdata;
var i,a,b,c:longint;
begin
 readln(n);
 for i:=1 to n do
  begin
  readln(a,b,c);
  G[a,b]:=c;
  end;
end;

procedure DFS(chiclo:longint);
begin
 por[k]:=chiclo; inc(k); used[chiclo]:=true;
 for i:=1 to n do
  if ((G[chiclo,i]<>0) or (G[i,chiclo]<>0)) and (not(used[i])) then
   begin DFS(i); break; end;
end;

procedure outputdata;
begin
 writeln(sum);
end;

begin
 inputdata;
 k:=1; DFS(1); por[k]:=1;
 sum1:=0; sum2:=0;
 for i:=1 to k-1 do
  begin
  if (G[por[i],por[i+1]]<>0) and (G[por[i+1],por[i]]=0) then inc(sum1,g[por[i],por[i+1]]);
  if (G[por[i],por[i+1]]=0) and (G[por[i+1],por[i]]<>0) then inc(sum2,g[por[i+1],por[i]]);
  end;
 sum:=min(sum1,sum2);
 outputdata;
end.