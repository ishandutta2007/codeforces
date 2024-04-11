{-# OPTIONS -O2 -optc-O2 -funbox-strict-fields #-}

import Data.List

import Control.Monad
import Control.Applicative

autoCan a [] = True
autoCan [] b = False
autoCan (x:xs) (y:ys)
  | x == y = autoCan xs ys
  | otherwise = autoCan xs (y:ys)

main :: IO ()
main = do
  a <- getLine
  b <- getLine
  if sort a == sort b
    then putStrLn "array"
  else if autoCan a b
    then putStrLn "automaton"
  else if autoCan (sort a) (sort b)
    then putStrLn "both"
  else
    putStrLn "need tree"