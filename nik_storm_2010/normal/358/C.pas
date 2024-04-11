uses
  math;
const
  ll=500000;
  o1='pushStack';
  o2='pushQueue';
  o3='pushFront';
  o4='pushBack';
  i1='popStack';
  i2='popQueue';
  i3='popFront';
  i4='popBack';
var
  kind,good:array[0..ll] of longint;
  ans,i,n,j,nom,max1,max2,max3,nom1,nom2,nom3:longint;

begin
  readln(n);
  for i:=1 to n do
  begin
    readln(kind[i]);
    if (kind[i]<>0) then continue;
    for j:=i-1 downto 0 do if (kind[j]=0) then begin nom:=j; break; end;
    max1:=0;
    nom1:=0;
    max2:=0;
    nom2:=0;
    max3:=0;
    nom3:=0;
    for j:=i-1 downto nom+1 do
    begin
      if (kind[j]>max1) then
      begin
        max3:=max2;
        nom3:=nom2;
        max2:=max1;
        nom2:=nom1;
        max1:=kind[j];
        nom1:=j;
        continue;
      end;
      if (kind[j]>max2) then
      begin
        max3:=max2;
        nom3:=nom2;
        max2:=kind[j];
        nom2:=j;
        continue;
      end;
      if (kind[j]>max3) then
      begin
        max3:=kind[j];
        nom3:=j;
        continue;
      end;
    end;
    good[nom1]:=1;
    good[nom2]:=2;
    good[nom3]:=3;
    if (nom1<>0) then inc(good[i]);
    if (nom2<>0) then inc(good[i]);
    if (nom3<>0) then inc(good[i]);
  end;
  for i:=1 to n do
  begin
    if (kind[i]=0) then
    begin
      ans:=good[i];
      write(ans);
      if (ans>=1) then write(' ',i1);
      if (ans>=2) then write(' ',i2);
      if (ans>=3) then write(' ',i3);
      writeln;
      continue;
    end;
    if (good[i]=0) then begin writeln(o4); continue; end;
    if (good[i]=1) then begin writeln(o1); continue; end;
    if (good[i]=2) then begin writeln(o2); continue; end;
    if (good[i]=3) then begin writeln(o3); continue; end;
  end;
end.