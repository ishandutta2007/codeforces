uses math; const maxn = 100000;
var
    edge:array[1..2,0..maxn] of longint; color,k:array[0..maxn] of longint; tek,nom,kol,n,m,i,x,y:longint;


procedure quicksort(l,r:longint);
var i,j,d1,d2,w:longint;
begin
  i:=l; j:=r; w:=random(r-l+1)+l;
  d1:=edge[1,w]; d2:=edge[2,w];
  while i<=j do
    begin
      while (edge[1,i]<d1) or ((edge[1,i]=d1) and (edge[2,i]<d2)) do inc(i);
      while (edge[1,j]>d1) or ((edge[1,j]=d1) and (edge[2,j]>d2)) do dec(j);
      if i<=j then
        begin
          w:=edge[1,i]; edge[1,i]:=edge[1,j]; edge[1,j]:=w;
          w:=edge[2,i]; edge[2,i]:=edge[2,j]; edge[2,j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


begin

  readln(n,m); kol:=0;
  for i:=1 to n do read(color[i]); readln;
  for i:=1 to m do
    begin
      readln(x,y);
      if color[x]<>color[y] then
        begin
          inc(kol);
          edge[1,kol]:=min(color[x],color[y]);
          edge[2,kol]:=max(color[x],color[y]);
        end;
    end;
  randomize; quicksort(1,kol);
  for i:=1 to kol do
    if (i=1) or not((edge[1,i]=edge[1,i-1]) and (edge[2,i]=edge[2,i-1])) then
    begin
      inc(k[edge[1,i]]); inc(k[edge[2,i]]);
    end;
  tek:=-1;
  for i:=1 to n do
    if (k[color[i]]>tek) or ((k[color[i]]=tek) and (color[i]<nom)) then
    begin
      tek:=k[color[i]]; nom:=color[i];
    end;
  writeln(nom);

end.