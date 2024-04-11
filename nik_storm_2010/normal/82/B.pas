Program B82;
Var
  a : array[1..200] of ansistring;
  d : array[1..200] of longint;
  e : array[1..200,1..200] of longint;
  s : array[1..200]  of ansistring;
  n,kolmnog,i,j,koef,nom : longint;


procedure inputdata;
var i,kol,ch,k,j:longint;
     s:string;
 begin
  readln(n);
   kol:=n*(n-1) div 2;
    for i:=1 to kol do
     begin
      read(k);
       for j:=1 to k do
        begin
         read(ch);
          str(i,s);
           a[ch]:=a[ch]+s;
        end;
       readln;
     end;
 end;


procedure outputdata;
var i,j:longint;
 begin
  for i:=1 to n do
   begin
    write(d[i],' ');
     for j:=1 to d[i] do write(e[i,j],' ');
    writeln;
   end;
  halt;
 end;


Begin

  kolmnog:=0;
   inputdata;
    if n = 2 then
     begin
      for i:=1 to 200 do
       if a[i]<>'' then
        begin
         inc(kolmnog);
          d[kolmnog]:=1;
           e[i,1]:=i;
            nom:=i;
             break;
        end;
      inc(kolmnog);
      for i:=nom+1 to 200 do
       if a[i]<>'' then
        begin
          inc(d[kolmnog]);
           e[kolmnog,d[kolmnog]]:=i;
        end;

     end;
   for i:=1 to 200 do
    if a[i]<>''
     then
      begin
       koef:=0;
        for j:=1 to kolmnog do
         if a[i]=s[j]
          then
           begin
            inc(d[j]);
             e[j,d[j]]:=i;
              koef:=1;
               break;
           end;
       if koef=0
        then
         begin
          inc(kolmnog);
           d[kolmnog]:=1;
            e[kolmnog,d[kolmnog]]:=i;
             s[kolmnog]:=a[i];
         end;

      end;

  outputdata;

End.