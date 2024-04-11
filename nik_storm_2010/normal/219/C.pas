var
    f1,f2:array[1..500000,1..26] of longint; st:array[1..500000] of longint; aa:array[1..500000] of char;
      tek,bon,min1,min2,c1,c2,j,n,k,i:longint; s:ansistring; help:string[26];


begin

  readln(n,k); readln(s); for i:=1 to n do st[i]:=ord(s[i])-64;
  for tek:=1 to n do
    if tek = 1 then
      begin
        for i:=1 to k do
          if i<>st[1] then f1[1,i]:=1
        else f1[1,i]:=0;
      end
        else
      begin
        min1:=maxlongint; min2:=maxlongint;
        for i:=1 to k do
          if f1[tek-1,i]<min1 then
            begin
              min2:=min1; c2:=c1;
              min1:=f1[tek-1,i]; c1:=i;
            end
              else if f1[tek-1,i]<min2 then
                begin
                  min2:=f1[tek-1,i];
                  c2:=i;
                end;
        for i:=1 to k do
          if i=c1 then
            begin
              if st[tek]=i then bon:=0 else bon:=1;
              f1[tek,i]:=min2+bon; f2[tek,i]:=c2;
            end
              else
            begin
              if st[tek]=i then bon:=0 else bon:=1;
              f1[tek,i]:=min1+bon; f2[tek,i]:=c1;
            end;
      end;

  min1:=maxlongint;
  for i:=1 to k do
    if min1>f1[n,i] then
      begin
        min1:=f1[n,i]; j:=i;
      end;
  help:='ABCDEFGHIJKLMNOPQRSTUVWXYZ';
  for i:=n downto 1 do
    begin
      aa[i]:=help[j];
      j:=f2[i,j];
    end;
  writeln(min1);
  for i:=1 to n do write(aa[i]);


end.