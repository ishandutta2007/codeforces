var
  isFriend : array[1..2000,1..2000] of integer;
   stroka : array[1..2000] of string;  a : array[1..3,1..1000] of longint;
    answer, n, different, i, j, finish, nom1, nom2, t : longint;
     s : string; c : char;


procedure poisk(s:string; var nom:longint);
var i:longint;
 begin
  for i:=1 to finish do
   if stroka[i] = s then begin nom:=i; exit; end;

  inc(finish);
   stroka[finish]:=s;
  nom:=finish;
 end;


begin

  readln(n,different); finish:=0;
   for i:=1 to n do
    begin
     s:='';
      while true do
       begin
        read(c);
         if c = ' ' then break;
        s:=s+c;
       end;
     poisk(s,nom1);

     s:='';
      while true do
       begin
        read(c);
         if c = ' ' then break;
        s:=s+c;
       end;
     poisk(s,nom2);

     readln(t);

     a[1,i]:=nom1;
      a[2,i]:=nom2;
     a[3,i]:=t;
    end;

  for i:=1 to n do
   for j:=i+1 to n do
    if (a[1,i]=a[2,j]) and (a[2,i]=a[1,j]) and (0<a[3,j]-a[3,i]) and (a[3,j]-a[3,i]<=different)
   then
    begin
     if isFriend[a[1,i],a[2,i]] <> 2 then inc(answer);
      isFriend[a[1,i],a[2,i]]:=2;
     isFriend[a[2,i],a[1,i]]:=2;
    end;

  writeln(answer);
   for i:=1 to finish do
    for j:=1 to finish do
     if isFriend[i,j] = 2
      then
     begin
      writeln(stroka[i],' ',stroka[j]);
       isFriend[i,j]:=0;
      isFriend[j,i]:=0;
     end;

end.