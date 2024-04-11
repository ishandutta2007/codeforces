Var
    f: array[1..3,1..3] of char;
     used: array[1..3,1..3] of boolean;
      kolX,kol0,i,j,k0,kX: longint;
       winX,win0: boolean;


procedure finish(answer:string);
 begin
   writeln(answer);
  halt;
 end;


procedure increase(c:char);
 begin
  if c = 'X' then winX:=true else win0:=true;
 end;

procedure incr(c:char);
 begin
  if c = 'X' then inc(kX) else inc(k0);
 end;


procedure check(c:char);
var i,j,y:longint;
     p1,p2: boolean;
 begin
  fillchar(used,sizeof(used),false);
  for i:=1 to 3 do
   begin
    p1:=true; p2:=true;
     for j:=1 to 3 do
      begin
       if f[i,j]<>c then p1:=false;
       if f[j,i]<>c then p2:=false;
      end;

     if p1 = true
      then
       begin
        increase(c);
         for j:=1 to 3 do used[i,j]:=true;
       end;
     if p2 = true
      then
       begin
        increase(c);
         for j:=1 to 3 do used[j,i]:=true;
       end;
   end;

  if (f[1,1]=c) and (f[2,2]=c) and (f[3,3]=c) then begin used[1,1]:=true; used[2,2]:=true; used[3,3]:=true; increase(c); end;
  if (f[3,1]=c) and (f[2,2]=c) and (f[1,3]=c) then begin used[3,1]:=true; used[2,2]:=true; used[1,3]:=true; increase(c); end;
   for i:=1 to 3 do
    for j:=1 to 3 do
     if used[i,j]=true then incr(c);
 end;


Begin

  readln(f[1,1],f[1,2],f[1,3]);
   readln(f[2,1],f[2,2],f[2,3]);
    readln(f[3,1],f[3,2],f[3,3]);

  kolX:=0; kol0:=0;
   for i:=1 to 3 do
    for j:=1 to 3 do
     begin
      if f[i,j] = 'X' then inc(kolX);
      if f[i,j] = '0' then inc(kol0);
     end;
  if ((kolX=kol0) = false) and ((kolX-kol0=1) = false) then finish('illegal');

  check('X'); check('0');
   if ((winX=true) and (win0=true)) or ((winX=true) and (kX>5)) or ((win0=true) and (k0>5)) or ((winX=true)and(kolX=kol0)) or ((win0=true)and(kolX<>kol0)) then finish('illegal');
    if winX = true then finish('the first player won');
     if win0 = true then finish('the second player won');
      if (kolX=5) and (kol0=4) then finish('draw');

  if kolX=kol0 then finish('first') else finish('second');

End.