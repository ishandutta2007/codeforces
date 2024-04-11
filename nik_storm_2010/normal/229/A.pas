uses math;
var
    a:array[1..101,1..10001] of char; f:array[1..101,1..10001] of longint;
      used:array[1..100] of boolean; answer,tek,i,j,n,m:longint;


function nextright(nom,i:longint):longint;
begin
  while true do
    begin
      if a[nom,i]='1' then exit(i);
      i:=i+1; if i>m then i:=1;
    end;
end;


function nextleft(nom,i:longint):longint;
begin
  while true do
    begin
      if a[nom,i]='1' then exit(i);
      i:=i-1; if i=0 then i:=m;
    end;
end;


procedure update(nom:longint);
var l1,l2,left,right,i:longint;
begin
  left:=nextleft(nom,1); right:=nextright(nom,1);
  for i:=1 to m do
    begin
      if i<left  then l1:=(i+m)-left  else l1:=i-left;
      if right<i then l2:=(right+m)-i else l2:=right-i;
      f[nom,i]:=min(l1,l2);
      if a[nom,i]='1' then begin left:=i; right:=nextright(nom,i+1); end;
    end;
end;


begin

  readln(n,m); for i:=1 to n do for j:=1 to m do f[i,j]:=maxlongint;
  for i:=1 to n do
    begin
      for j:=1 to m do
      begin
        read(a[i,j]);
        if a[i,j]='1' then used[i]:=true;
      end;
      readln;
    end;
  for i:=1 to n do
    begin
      if used[i]=false then begin writeln(-1); halt; end;
      update(i);
    end;
  answer:=maxlongint;
  for j:=1 to m do
    begin
      tek:=0;
      for i:=1 to n do tek:=tek+f[i,j];
      answer:=min(tek,answer);
    end;
  writeln(answer);

end.