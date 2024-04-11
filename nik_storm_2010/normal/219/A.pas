var
    kol:array[97..122] of longint; s,stek:ansistring;
     k,d,i,j:longint;


begin

  readln(k); stek:='';
  readln(s); d:=length(s);
  for i:=1 to d do inc(kol[ord(s[i])]);

  for i:=97 to 122 do
    if kol[i] mod k = 0 then
      begin
        for j:=1 to kol[i] div k do stek:=stek+chr(i);
      end
        else
      begin
        writeln(-1);
        halt;
      end;

  for i:=1 to k do write(stek);

end.