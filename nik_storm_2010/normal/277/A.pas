var
    lang:array[1..100,0..100] of longint; edge:array[1..3,1..10000] of longint;
      p:array[1..100] of longint; answer,kol,i,j,k,x,y,n,m:longint;


procedure quicksort(l,r:longint);
var i,j,d,w:longint;
begin
  i:=l; j:=r; d:=edge[3,random(r-l+1)+l];
  while i<=j do
    begin
      while edge[3,i]<d do inc(i);
      while edge[3,j]>d do dec(j);
      if i<=j then
        begin
          w:=edge[1,i]; edge[1,i]:=edge[1,j]; edge[1,j]:=w;
          w:=edge[2,i]; edge[2,i]:=edge[2,j]; edge[2,j]:=w;
          w:=edge[3,i]; edge[3,i]:=edge[3,j]; edge[3,j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


function findset(i:longint):longint;
begin
  if p[i]<>i then p[i]:=findset(p[i]);
  findset:=p[i];
end;


procedure union(i,j:longint);
begin
  i:=findset(i); j:=findset(j);
  if random(2)=1 then p[i]:=p[j] else p[j]:=p[i];
end;


begin

  readln(n,m); answer:=0;
  for i:=1 to n do
    begin
      read(lang[i,0]); if lang[i,0]=0 then inc(answer);
      for j:=1 to lang[i,0] do
        begin
          read(x);
          lang[i,x]:=1;
        end;
      readln;
    end;
  kol:=0;
  for i:=1 to n do
    for j:=i+1 to n do
      if (lang[i,0]<>0) and (lang[j,0]<>0) then
        begin
          inc(kol); edge[1,kol]:=i; edge[2,kol]:=j; edge[3,kol]:=1;
          for k:=1 to m do
            if (lang[i,k]=1) and (lang[j,k]=1) then begin edge[3,kol]:=0; break; end;
        end;
  randomize; quicksort(1,kol);
  for i:=1 to n do p[i]:=i;
  for i:=1 to kol do
    begin
      x:=findset(edge[1,i]); y:=findset(edge[2,i]);
      if x<>y then
        begin
          union(x,y);
          answer:=answer+edge[3,i];
        end;
    end;
  writeln(answer);
end.