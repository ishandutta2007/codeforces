var
    a:array[1..3,0..200010] of longint; used:array[0..2000010] of boolean;
      mm,max,nom,aa,pred,n,m,i,x,y:longint;


procedure quicksort(l,r:longint);
var i,j,d1,d2,w:longint;
begin
  i:=l; j:=r; w:=random(r-l+1)+l;
  d1:=a[1,w]; d2:=a[2,w];
  while i<=j do
    begin
      while (a[1,i]<d1) or ((a[1,i]=d1)and(a[2,i]>d2)) do inc(i);
      while (a[1,j]>d1) or ((a[1,j]=d1)and(a[2,j]<d2)) do dec(j);
      if i<=j then
        begin
          w:=a[1,i]; a[1,i]:=a[1,j]; a[1,j]:=w;
          w:=a[2,i]; a[2,i]:=a[2,j]; a[2,j]:=w;
          w:=a[3,i]; a[3,i]:=a[3,j]; a[3,j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


begin

  readln(n,m); mm:=0;
  for i:=1 to m do
    begin
      readln(x,y);
      a[1,i]:=x; a[2,i]:=x+y-1; a[3,i]:=i;
      if a[2,i]>mm then mm:=a[2,i];
    end;
  randomize; quicksort(1,m);
  max:=0; pred:=0; a[2,m+1]:=mm; i:=1;
  while i<=m do
    begin
      if (a[1,i]<=pred) then
        begin
          if a[2,i]>max then begin max:=a[2,i]; nom:=a[3,i]; end;
          inc(i);
        end
          else
        begin
          if ((a[1,i]-pred=1) and (a[2,i]>max)) or (max<=pred)
            then begin pred:=a[2,i]; used[a[3,i]]:=true; inc(i); end
            else begin pred:=max; used[nom]:=true; end;
          max:=0; nom:=0;
        end;
    end;
  if pred<>mm then used[nom]:=true; aa:=0;
  for i:=1 to m do if used[i]=false then inc(aa);
  writeln(aa);
  for i:=1 to m do if used[i]=false then write(i,' ');

end.