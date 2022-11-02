var
  a:array[0..10,1..20] of string; leng,b:array[0..10] of longint; c:char;
  used:array[1..4] of boolean; n,kol,nm,k,i,q:longint; s:string;


procedure factor(s:string;nom,k:longint);
var i,j:longint;
begin
  leng[nom]:=k; i:=1; j:=1;
  while j<=k do
  begin
    if s[i]=' ' then inc(j) else a[nom,j]:=a[nom,j]+s[i];
    inc(i);
  end;
end;


procedure rec(nom:longint);
var all,num,i,j,t:longint;
begin
  if nom=n+1 then
  begin
    all:=0;
    for i:=1 to n do for j:=i+1 to n do if b[i]>b[j] then inc(all);
    num:=-1;
    for t:=1 to k do
    begin
      i:=1;
      for j:=1 to leng[t] do if a[0,b[i]]=a[t,j] then
      begin
        inc(i);
        if i=n+1 then begin num:=t; break; end;
      end;
      if num=t then break;
    end;
    if (num<>-1) and ((all<kol) or ((all=kol)and(nm>num))) then
    begin
      kol:=all; nm:=num;
    end;
  end
    else
  begin
    for i:=1 to n do if used[i]=false then
    begin
      used[i]:=true; b[nom]:=i;
      rec(nom+1);
      used[i]:=false;
    end;
  end;
end;


begin

  readln(n); readln(s); factor(s+' ',0,n);
  readln(k);
  for i:=1 to k do
  begin
    read(q); read(c); readln(s);
    factor(s+' ',i,q);
  end;
  kol:=maxlongint; nm:=0;
  rec(1);
  if kol=maxlongint then writeln('Brand new problem!') else
  begin
    writeln(nm);
    write('[:'); for i:=1 to n*(n-1) div 2-kol+1 do write('|'); writeln(':]');
  end;

end.